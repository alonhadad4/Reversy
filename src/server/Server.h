class Server {
    public:
        Server(int port);
        void start();
        void stop();

    private:
        int port;
        int serverSocket;
        int cp1 = -1;
        int cp2 = -1;

        void handleClient(int clientSocket);
        void startGameLoop();
        void sendSign(int sign,int cp);

};