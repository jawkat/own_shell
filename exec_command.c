#include "main.h"
/**
 * exec_command - Executes the command received as input.
 *
 * @cmd: commmand line.
 * @envp: the environment variable.
 * @argv: The argument vector containing the command and its arguments.
 *
 * Return: 0 on successful execution, -1 on failure.
 */
int exec_command(char **cmd, char **argv, char **envp)
{

	pid_t child_pid;
	int status;
	char *path;
	int i;
 
 	path = cmd[0];
 
	child_pid = fork();
	
	if (child_pid == 0) /* the child work */
	{
		if (execve(path, cmd, envp) == -1)
		{
			perror(argv[0]);
			
			for (i = 0; cmd[i]; i++)
			free(cmd[i]), cmd[i] = NULL;
			free(cmd), cmd = NULL;
			/* _free3(cmd); */
			exit(0);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		/* _free3(cmd); */	
	for (i = 0; cmd[i]; i++)
		free(cmd[i]), cmd[i] = NULL;
		
	free(cmd), cmd = NULL;		
	}
	return (WEXITSTATUS(status));
}





