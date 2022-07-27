#include<iostream>
#include <fstream>

int main(int argc, char** argv)
{
	std::cout << "Testing popen" << std::endl;
	int status = -1;
	char         buffer[128];
	std::string result = "";
	std::string command = "\"\"C:\\Program Files\\veritas\\NetBackup\\bin\\nbmysql.exe\" -o backup -C dl380g10-109v30.vxindia.veritas.com -S dl380g10-109v30.vxindia.veritas.com -P BACKUPNOW+d22fd163-9c22-4150-b131-9e0b62ab50e3 -s FULL -p 3306 -b auto -l \"C:\\ProgramFiles\\MySQL\\MySQL Server 8.0\\lib\\\" -instance MySQL80 -pgid MYSQL_INSTANCE_dl380g10-109v30.vxindia.veritas.com_3306\"";
	//std::string command = "\"C:\\Program Files\\veritas\\NetBackup\\bin\\nbmysql.exe\"";
	                        "\"C:\\Program Files\\MySQL\\MySQL Server 8.0\\lib\\\"";
	std::string command1 = "\"C:\\Program Files\\veritas\\NetBackup\\bin\\nbmysql.exe\" -o backup -C dl380g10-109v30.vxindia.veritas.com -S dl380g10-109v30.vxindia.veritas.com -P BACKUPNOW+d22fd163-9c22-4150-b131-9e0b62ab50e3 -s FULL -p 3306 -b auto -l \"C:\\ProgramFiles\\MySQL\\MySQL Server 8.0\\lib\\\" -instance MySQL80 -pgid MYSQL_INSTANCE_dl380g10-109v30.vxindia.veritas.com_3306";
	std::string inFilename = "\"C:\\Program Files\\veritas\\NetBackup\\bin\\bpend_notify_stdin.txt\"";
	std::string outFilename = "\"C:\\Program Files\\veritas\\NetBackup\\bin\\bpend_notify_stdout.txt\"";
	std::string errFilename = "\"C:\\Program Files\\veritas\\NetBackup\\bin\\bpend_notify_stderr.txt\"";

	FILE* pipe = _popen(command.c_str(), "r");
	command1.insert(0,"\"");
	command1.append("\"");

	if (!pipe) {
		std::cout << "popen Failed" << std::endl;
		return -1;
	}

	try {
		// Collect stdout logs from the process
		while (fgets(buffer, sizeof buffer, pipe) != NULL)
			result += buffer;

		// Write Logs on file
		std::ofstream outfile;

		// open file in append mode instead of overwrite

		outfile.open(inFilename.c_str(), std::ios_base::app);
		outfile << std::endl;
		outfile << command;
		outfile.close();

		outfile.open(outFilename.c_str(), std::ios_base::app);
		outfile << std::endl;
		outfile << result;
		outfile.close();

		outfile.close();
	}
	catch (...)
	{
		throw;
	}

	status = _pclose(pipe);
	return status;
}