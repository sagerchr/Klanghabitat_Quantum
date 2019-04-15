var host = WScript.FullName;
var shell = WScript.CreateObject('WScript.Shell');
if (host.match(/wscript\.exe$/i)) {
    shell.Exec('cscript -nologo ' + WScript.ScriptFullName);
    WScript.Quit();
}

var cmdargs = WScript.Arguments;
var cmdargc = cmdargs.length;
var args = new Array;
var argc = 0;
var signaddr = null;
var disasm = null;
var i = 0;
while (i < cmdargc) {
    if (cmdargs(i) == '-d' || cmdargs(i) == '--disasm')
        disasm = (i + 1 < cmdargc) ? cmdargs(++i) : null;
    else if (cmdargs(i) == '-s' || cmdargs(i) == '--sign')
        signaddr = (i + 1 < cmdargc) ? cmdargs(++i) : null;
    else {
        args.push(cmdargs(i));
        argc++;
    }
    i++;
}
if (args.length < 3 || 4 < args.length) {
    var usage = 'usage: ' + WScript.ScriptName + ' [-d|--disasm file]'
        + '[-s|--sign address] tooldir elffile binfile [disasmfile]';
    WScript.Stderr.WriteLine(usage);
    WScript.Quit();
}
var tooldir = args[0];
var elffile = args[1];
var binfile = args[2];
if (args.length == 4)
    disasm = args[3];

function RunCommand(sh, cmd) {
    WScript.StdOut.WriteLine(cmd);
    var exec = sh.Exec(cmd);
    var out = '';
    var err = '';
    while (!exec.StdOut.AtEndOfStream || !exec.StdErr.AtEndOfStream) {
        out += exec.StdOut.Read(1024);
        err += exec.StdErr.Read(1024);
        WScript.Sleep(200);
    }
    if (exec.Status != 0)
        WScript.StdOut.WriteLine('Status: ' + exec.Status);
    //WScript.StdOut.WriteLine('Output: ' + out);
    //WScript.StdOut.WriteLine('Stderr: ' + err.length != 0 ? err : '<null>');
}

if (tooldir.slice(-1) != '\\')
    tooldir += '\\';
if (signaddr != null) {
    var elfdwt = tooldir + 'ARM\\BIN\\ElfDwT';
    var signargs = new Array(elfdwt, elffile, 'baseaddress(' + signaddr + ')')
    RunCommand(shell, signargs.join(' '));
}
var fromelf = tooldir + 'ARM\\ARMCC\\bin\\fromelf';
var binargs = new Array(fromelf, '--bin', '--output', binfile, elffile);
RunCommand(shell, binargs.join(' '));

if (disasm != null) {
    var disargs = new Array(fromelf, '--text', '-c', '--output', disasm,
        elffile);
    RunCommand(shell, disargs.join(' '));
}
