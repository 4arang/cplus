//get �Լ��� ���� ���� ������ �ʵ� starttime, endtime
/*
stime�� ����ð����� �ʱ�ȭ�ϴ� �μ����� ������
stime�� ���� �ð����� �缳���ϴ� start()�Լ�
etime�� ����ð����� �����ϴ� stop() �Լ�
��ž��ġ ����ð��� ms�� ��ȯ�ϴ� getElapsedtime() �Լ�
���� ������ ����Ͽ� 100,000���� ���ڸ� �����ϴµ� �ɸ� �ð� ����
*/
#include <time.h>


class stopwatch
{
	double startTime, endTime;

public:
	double getStime() { return startTime; }
	double getEtime() { return endTime; }
	stopwatch() : startTime( clock()) {}
	void start()
	{
		startTime = clock();
	}
	void stop()
	{
		endTime =clock();
	}
	double getElapsedTime()
	{
		return (endTime - startTime);
	}
};

