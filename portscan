#Programa para realizar Port Scanning obtido no curso NPP da DESEC - Melhorias futuras

#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
	int mysock;
	int conecta;

	int porta;
	int inicio = 0;
	int final = 65535;
	char *destino;
	destino = argv[1];

	struct sockaddr_in alvo;

	if (argc<1)
	{
		printf("Modo de uso: ./portscan 192.168.0.1 \n");
		return 1;
	}
	else
	{
		for(porta=inicio;porta<final;porta++)
		{
			mysock = socket(AF_INET,SOCK_STREAM,0);
			alvo.sin_family = AF_INET;
			alvo.sin_port = htons(porta);
			alvo.sin_addr.s_addr = inet_addr(destino);

			conecta = connect(mysock, (struct sockaddr *)&alvo, sizeof alvo);

			if (conecta == 0)
			{
				printf("Porta %d - status [ABERTA] \n",porta);
				close(mysock);
				close(conecta);
			}	
			else
			{
				close(mysock);
				close(conecta);
			}
		}
	}
}
