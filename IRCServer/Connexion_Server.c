	#include <stdio.h>
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <stdlib.h>
	#include <netdb.h>
	#include <strings.h>
	#include <arpa/inet.h>
	#include <unistd.h>

	void error(char *msg)
	{
	perror(msg);
	exit(1);
	}
	int main(int argc, char *argv[])
	{
		int sockfd,newsockfd,num_port,serveur_T;
		socklen_t client_T;
		char buffer[200];
		struct sockaddr_in adr_serveur, adr_client;
		int n;
		
		
		if (argc < 2)
		{
			fprintf(stderr, "nombre d'arguments est insuffisant\n");
			exit(1);
		}
		sockfd=socket(AF_INET, SOCK_STREAM, 0);
		if (sockfd < 0)
		{
			error("erreur de creation de socket");
		}
		
		serveur_T=sizeof(adr_serveur);
		bzero((char*)&adr_serveur, serveur_T);
		num_port=atoi(argv[1]);
		
		adr_serveur.sin_family=AF_INET;
		adr_serveur.sin_addr.s_addr=INADDR_ANY;
		adr_serveur.sin_port=htons(num_port);
		
		serveur_T=sizeof(adr_serveur);
		if (bind ( sockfd,(struct sockaddr *) &adr_serveur,serveur_T)<0)
		{
			error(" Erreur de binding");
		}
		
		listen (sockfd,5);
		client_T= sizeof(adr_client);
		newsockfd= accept(sockfd,(struct sockaddr *) &adr_client,&client_T);
		
		if ( newsockfd<0)
		{
			error("Erreur socket accept");
		}
		bzero(buffer, 200);
		
		
		
	return 0;}
