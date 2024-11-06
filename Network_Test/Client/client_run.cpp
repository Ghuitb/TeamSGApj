#include "Net_socket.h"
#include "Net_IO.h"
#include "Net_data.h"
#include "Net_SendData.h"

int main()
{
	// 네트워크 송수신 데이터 구조 생성
	Net_Data data;

	// 서버와 연결되는 소켓을 생성하고 전달하는 역할을 실행하는 Net_Socket의 객체를 생성
	Net_Socket sock;
	if (!sock.InitSocket())		// 정상 생성 확인
		return 1;

	// 데이터 송수신을 담당하는 Net_IO 객체를 생성하며 소켓과 데이터 구조를 전달
	Net_IO IO(sock.GetSocket(), data);

	// 클라이언트에서 서버로 전송할 데이터를 수집, 가공해서 송수신을 담당하는 Net_SendData 객체 생성
	Net_SendData sender(data);

	// 데이터 송수신을 담당하는 Net_IO 객체를 사용, 서버로부터 데이터를 전송받는 스레드를 생성
	IO.recvThread();

	// 클라이언트에서 데이터를 입력받고, 서버로 데이터를 송신하는 함수 실행
	while (true)
	{
		sender.getUserInput();		// 데이터 입력
		IO.sendData();				// 데이터 송신
	}
	// 데이터를 Net_Data 데이터 구조를 각 객체에 전달했기 때문에 함수의 인수로 데이터를 넘겨주지 않아도 됨
	// 그런데 종속성이나 다른 문제들이 발생할 수 있는 상황에 대해 잘 생각해보아야함

	return 0;
}

