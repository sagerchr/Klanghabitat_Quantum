@ECHO OFF

REM IAR Headless Builds:https://www.iar.com/support/tech-notes/general/build-from-the-command-line/
REM headless-build.bat is missing an import switch...so need to start at a lower level: https://community.nxp.com/thread/388962

REM First copy any updated header files or libraries to the local folder
copy /Y ..\..\..\AudioWeaver\Include\Framework.h ..\..\Lib\AWEInclude
copy /Y ..\..\..\AudioWeaver\Include\Errors.h ..\..\Lib\AWEInclude
copy /Y ..\..\..\AudioWeaver\Include\FileSystem.h ..\..\Lib\AWEInclude
copy /Y ..\..\..\AudioWeaver\Include\FractMath.h ..\..\Lib\AWEInclude
copy /Y ..\..\..\AudioWeaver\Include\MathHelper.h ..\..\Lib\AWEInclude
copy /Y ..\..\..\AudioWeaver\Include\ModCommon.h ..\..\Lib\AWEInclude
copy /Y ..\..\..\AudioWeaver\Include\PlatformAPI.h ..\..\Lib\AWEInclude
copy /Y ..\..\..\AudioWeaver\Include\ProxyIDs.h ..\..\Lib\AWEInclude
copy /Y ..\..\..\AudioWeaver\Include\TargetProcessor.h ..\..\Lib\AWEInclude
copy /Y ..\..\..\AudioWeaver\Include\TuningHandler.h ..\..\Lib\AWEInclude
copy /Y ..\..\..\AudioWeaver\Include\VectorLib.h ..\..\Lib\AWEInclude
copy /Y ..\..\..\AudioWeaver\Include\Modules\*.h ..\..\Lib\AWEInclude\Modules

copy /Y ..\..\..\AudioWeaver\Include\Targets\ARM_CortexM4_TargetProcessor.h ..\..\Lib\AWEInclude\Targets
copy /Y ..\..\..\AudioWeaver\Include\Targets\StandardDefs.h ..\..\Lib\AWEInclude\Targets

copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\EWARM\Standard.a ..\..\Lib\AWELibs\EWARM
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\EWARM\ModuleHelperLib.a ..\..\Lib\AWELibs\EWARM
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\EWARM\VectorLib.a ..\..\Lib\AWELibs\EWARM
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\EWARM\ST\CFramework.a ..\..\Lib\AWELibs\EWARM
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\EWARM\FlashFileSystem.a ..\..\Lib\AWELibs\EWARM
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\EWARM\Q15_Demo_ASRCLib.a ..\..\Lib\AWELibs\EWARM
IF EXIST ..\..\..\AudioWeaver\Lib\ARM_M7\EWARM\versionInfo.txt COPY /Y ..\..\..\AudioWeaver\Lib\ARM_M7\EWARM\versionInfo.txt ..\..\Lib\AWELibs\EWARM

ECHO ON
"C:\Program Files (x86)\IAR Systems\Embedded Workbench 8.0\common\bin\IarBuild.exe" STM32F769_Discovery.ewp -build Release -log all

CALL :checkError

EXIT /B 0

:checkError
  IF %ERRORLEVEL% NEQ 0 (
      echo Error while building IAR for STM32F769i
      EXIT 1
  )
