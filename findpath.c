#include "lib.h"
/**
 * f_ex_path - find the excutive path of the given command.
 * @command:.
 * @av:.
 * @cnt:.
 * Return: return the directory path of the command.
 */
char *f_ex_path(const char *command, char *av[], int cnt)
{
	char *car, *pth_cpy, *pth_env, *dir, *result;
	int path_len = 0, offset;
	char exec_path[MX_PTH_LNTH];
	struct stat buf;

	pth_env = get_pth("PATH");
	pth_cpy = _strdup(pth_env);
	if (pth_cpy == NULL || pth_env == NULL)
		return (NULL);
	dir = strtok(pth_cpy, ":");
	while (dir != NULL)
	{
		offset = 0;
		path_len = _strlen(dir) + 1 + _strlen(command) + 1;
		strcpy(exec_path + 0, dir);
		offset += _strlen(dir);
		exec_path[offset++] = '/';
		strcpy(exec_path + offset, command);
		if (access(exec_path, X_OK) == 0)
		{
			result = _strdup(exec_path);
			free(pth_cpy);
			return (result);
		}
		car = exec_path;
		dir = strtok(NULL, ":");
	}
	if (stat(car, &buf) == -1)
	{
		handle_errors((char **)&command, av, cnt, 127);
		return ("127");
	}
	if (access(car, X_OK) == -1)
	{
		handle_errors((char **)&command, av, cnt, 126);
		return ("126");
	}
	free(pth_cpy);
	return (NULL);
}
