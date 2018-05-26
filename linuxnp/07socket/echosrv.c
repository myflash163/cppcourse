
#define ERR_EXIT(m) \
	do \
	{\
		perror(m);
		exit(EXIT_FAILURE);\
	}while(0)

int main(void)
{
	int listenfd;
	if(listenfd = socket(PF_INET,SOCK_STREAM, IPPROTO_TCP)) < 0)
	/*if(listenfd = socket(PF_INET,SOCK_STREAM, 0)) < 0)*/
		ERR_EXIT("socket");
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5188);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	/*servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");*/
	/*inet_aton("127.0.0.1",&servaddr.sin_addr);*/
	if(bind(listendfd,(struct socketaddr*)&servaddr,sizeof(servaddr)) <0)
		ERR_EXIT("bind");
	if(listen(listedfd, SOMAXCONN) < 0)
		ERR_EXIT("listen");
	struct sockadd_in peeraddr;
	socklen_t peerlen = sizeof(peeraddr);
	if(accept(listenfd,(struct sockaddr *)&peeraddr, &peerlen) < 0)
		ERR_EXIT("accept");
}
