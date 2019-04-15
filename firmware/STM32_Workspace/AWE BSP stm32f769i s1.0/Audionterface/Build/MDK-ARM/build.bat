@ECHO OFF

ECHO ON

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

copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\MDK_ARM\Standard.lib ..\..\Lib\AWELibs\MDK_ARM
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\MDK_ARM\ModuleHelperLib.lib ..\..\Lib\AWELibs\MDK_ARM
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\MDK_ARM\VectorLib.lib ..\..\Lib\AWELibs\MDK_ARM
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\MDK_ARM\ST\CFramework.lib ..\..\Lib\AWELibs\MDK_ARM
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\MDK_ARM\FlashFileSystem.lib ..\..\Lib\AWELibs\MDK_ARM
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\MDK_ARM\Q15_Demo_ASRCLib.lib ..\..\Lib\AWELibs\MDK_ARM
IF EXIST ..\..\..\AudioWeaver\Lib\ARM_M7\MDK_ARM\versionInfo.txt COPY /Y ..\..\..\AudioWeaver\Lib\ARM_M7\MDK_ARM\versionInfo.txt ..\..\Lib\AWELibs\MDK_ARM

ECHO OFF

REM Delete old build log file
IF EXIST "%~dp0Project.log" DEL "%~dp0Project.log"

REM Run the build and save the error level if errors are present
SET FAILED=0
start "" /WAIT "C:\Keil_v5\UV4\UV4" -b "%~dp0Project.uvprojx" -q -o"%~dp0Project.log"
IF ERRORLEVEL 2 SET FAILED=%ERRORLEVEL%

REM Print result
TYPE "%~dp0Project.log"

REM Exit with error level
IF NOT "%FAILED%" == "0" EXIT /B %FAILED%

REM Return success
EXIT /B 0
