#include "Net_socket.h"
#include "Net_IO.h"
#include "Net_data.h"
#include "Net_SendData.h"

int main()
{
	// ��Ʈ��ũ �ۼ��� ������ ���� ����
	Net_Data data;

	// ������ ����Ǵ� ������ �����ϰ� �����ϴ� ������ �����ϴ� Net_Socket�� ��ü�� ����
	Net_Socket sock;
	if (!sock.InitSocket())		// ���� ���� Ȯ��
		return 1;

	// ������ �ۼ����� ����ϴ� Net_IO ��ü�� �����ϸ� ���ϰ� ������ ������ ����
	Net_IO IO(sock.GetSocket(), data);

	// Ŭ���̾�Ʈ���� ������ ������ �����͸� ����, �����ؼ� �ۼ����� ����ϴ� Net_SendData ��ü ����
	Net_SendData sender(data);

	// ������ �ۼ����� ����ϴ� Net_IO ��ü�� ���, �����κ��� �����͸� ���۹޴� �����带 ����
	IO.recvThread();

	// Ŭ���̾�Ʈ���� �����͸� �Է¹ް�, ������ �����͸� �۽��ϴ� �Լ� ����
	while (true)
	{
		sender.getUserInput();		// ������ �Է�
		IO.sendData();				// ������ �۽�
	}
	// �����͸� Net_Data ������ ������ �� ��ü�� �����߱� ������ �Լ��� �μ��� �����͸� �Ѱ����� �ʾƵ� ��
	// �׷��� ���Ӽ��̳� �ٸ� �������� �߻��� �� �ִ� ��Ȳ�� ���� �� �����غ��ƾ���

	return 0;
}

