/*ejemplo tomado de la pagina: http://www.chuidiang.com/clinux/rpc/rpc.php */

struct sumandos{int sumando1;int sumando2;};
program PROGRAMA_SUMA{	
version VERSION_SUMA{
int suma (sumandos)=1;
}=1;
}=0x20000001;
