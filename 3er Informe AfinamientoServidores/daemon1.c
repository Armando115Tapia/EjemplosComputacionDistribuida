/*para la implementacion de este programa se utilizo como referencia 
el siguiente programa:
 


*/

#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
pid_t pid, sid;

/*crear proceso hijo como clon del padre*/
pid = fork(); 
if (pid < 0) {exit(EXIT_FAILURE);}
if (pid > 0) {exit(EXIT_SUCCESS);}

/*mascara de usuario para los directorios 
y archivos creados por el demonio*/
umask(0);

/*Abrir una conexion al servidor syslog*/
openlog(argv[0],LOG_NOWAIT|LOG_PID,LOG_USER); 

/* Enviar un mensaje al demonio syslog*/
syslog(LOG_NOTICE, "EL demonio arranco con exito\n"); 

char *cwd = getcwd(NULL, 0);
syslog(LOG_NOTICE, "CWD: %s", cwd);
free(cwd);

/* Cambiar el directorio de trabajo actual*/
if ((chdir("/")) < 0) {
    syslog(LOG_ERR, "No se pudo cambiar al directorio root \n");
    exit(EXIT_FAILURE);}

char *ccwd = getcwd(NULL, 0);
syslog(LOG_NOTICE, "CWD: %s", ccwd);
free(ccwd);

/*Cerrar los descriptores estandar para entrada y salida*/
close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);

/*Demostrar el uso de registros en el log */
syslog(LOG_INFO, "Cerrados con exito los descriptores para entrada y salida \n");

/* this is optional and only needs to be done when your daemon exits */
closelog();

}
