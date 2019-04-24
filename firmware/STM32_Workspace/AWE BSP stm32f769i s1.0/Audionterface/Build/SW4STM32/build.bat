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

copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\SW4STM32\libStandard.a ..\..\Lib\AWELibs\SW4STM32
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\SW4STM32\libModuleHelperLib.a ..\..\Lib\AWELibs\SW4STM32
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\SW4STM32\libVectorLib.a ..\..\Lib\AWELibs\SW4STM32
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\SW4STM32\ST\libCFramework.a ..\..\Lib\AWELibs\SW4STM32
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\SW4STM32\libFlashFileSystem.a ..\..\Lib\AWELibs\SW4STM32
copy /Y ..\..\..\AudioWeaver\Lib\ARM_M7\SW4STM32\libQ15_Demo_ASRCLib.a ..\..\Lib\AWELibs\SW4STM32
IF EXIST ..\..\..\AudioWeaver\Lib\ARM_M7\SW4STM32\versionInfo.txt COPY /Y ..\..\..\AudioWeaver\Lib\ARM_M7\SW4STM32\versionInfo.txt ..\..\Lib\AWELibs\SW4STM32

SET CONSOLE=-vmargs -Dorg.eclipse.cdt.core.console=org.eclipse.cdt.core.systemConsole
C:\Ac6\SystemWorkbench\eclipsec.exe --launcher.suppressErrors -nosplash -application org.eclipse.cdt.managedbuilder.core.headlessbuild -cleanBuild STM32F769i_Discovery/Release -data .\workspace -import .\STM32F769i_Discovery %CONSOLE%

copy /Y STM32F769i_Discovery\Release\STM32F769i_Discovery_SW4STM32.bin ..\..\Bin