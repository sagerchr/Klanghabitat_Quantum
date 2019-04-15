var host = WScript.FullName;
if (host.match(/wscript\.exe$/i)) {
    var shell = WScript.CreateObject('WScript.Shell');
    shell.Exec('cscript -nologo ' + WScript.ScriptFullName);
    WScript.Quit();
}
var args = WScript.Arguments;
if (args.length != 2) {
    var usage = 'usage: ' + WScript.ScriptName + ' source destdir';
    WScript.Stderr.WriteLine(usage);
    WScript.Quit();
}
var source = args(0);
var destdir = args(1);
var fso = new ActiveXObject('Scripting.FileSystemObject');
if (!fso.FileExists(source)) {
    WScript.Stderr.WriteLine('file ' + source + ' does not exist');
    WScript.Quit();
}
if (!fso.FolderExists(destdir))
    fso.CreateFolder(destdir);
fso.CopyFile(source, destdir, true);
