#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "stopwatch.h"
#include "worker0.h"
const int LIM = 4;
int main()
{
	Waiter bob("홍길동", 314L, 5);
	Singer bev("조수미", 522L, 3);
	Waiter w_temp;
	Singer s_temp;

	Worker * pw[LIM] = { &bob, &bev, &w_temp, &s_temp };

	int i;
	for (i = 2; i < LIM; i++)
		pw[i]->Set();
	for (i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		std::cout << std::endl;
	}
	return 0;
}























/*
//sns 각 이용자의 친구 수 분석
//3 1 2 4 5 =>  2 3 4 3 2
using namespace std;

int solution(int N, int **relation);
int main()
{
	int N;
	cout << "전체 이용 자 수 : ";
	cin >> N;
	int *(*relation) = new int*[2] ();	//행
	for (int i = 0; i < 2; i++)
		relation[i] = new int[N*(N - 1) / 2]();	//열
	 //0으로 초기화
	int an = 0; //수열 첫번째
	int sum = 0; //계차수열 합 (N=5일때 0 4 7 9 10)
	for (int i = 0; i < N-1; i++)
	{
		int n;
		cout << i+1 << "번의 친구 수 : ";
		cin >> n;
		
		for (int j = 0; j < n; j++)
		{
			int fn; //friend number
			cout << j + 1 << "번째 친구 번호 : ";
			cin >> fn; 
			if (fn>i+1)//중복 제외한 경우만 
			{
				relation[0][sum+(fn-i-1)-1] = i+1; //(i+1, fn)
				relation[1][sum + (fn - i - 1) - 1] = fn;
			}	   					
		}
		an = N -1 -i;	//등차 공차=-1
		sum += an;		//등차 합 ->계차
	}
	solution(N, relation);
	for (int i = 0; i < 2; i++)
		delete[] relation[i];
	delete[] relation;
}
int solution(int N, int **relation)
{
	int cnt = 1; //친구 1~N
	int *(*friendArr) = new int*[N]();	//친구배열
	for (int i = 0; i < N; i++)
		friendArr[i] = new int[N]();	//열
	while (cnt <= 5)
	{
		int dcnt = 0; //직접친구
		cout << cnt << "의 직접친구 : ";
		for (int i = 0; i < N*(N - 1) / 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (relation[j][i] == cnt)	//해당번호가 나오면
				{
					dcnt++;
					if (j == 0)	//해당번호의 같은열 다른행(친구)를 출력
					{
						cout << relation[1][i] << " ";
						friendArr[cnt - 1][relation[1][i] - 1] = relation[1][i];//자기목록에 친구추가
						friendArr[relation[1][i] - 1][cnt - 1] = cnt; //친구목록에 자신추가
					}
					else
					{
						cout << relation[0][i] << " ";
						friendArr[cnt - 1][relation[0][i] - 1] = relation[0][i];
						friendArr[relation[1][i] - 1][cnt - 1] = cnt;
					}
				}
			}
		}
		cout << endl << cnt << "의 직접친구는 총 " << dcnt << "명" << endl;
		cnt++;
	}
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < 5; i++)
		{
		cout << i + 1 << "의 친구는 ";
		for (int j = 0; j < 5; j++)
			{
				//if (friendArr[i][j] != 0)
					cout << friendArr[i][j] << " ";
			}
		cout << endl;
		}
	
	cout << "----------------------------------------" << endl;
	cnt = 1; //초기화
	while (cnt <= 5)
	{
		int fcnt = 0; //최종친구
		cout << cnt << "의 최종친구 : ";
		for (int i = 0; i < N*(N - 1) / 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (relation[j][i] == cnt)	//해당번호가 나오면
				{
					fcnt++;
					if (j == 0)	//해당번호의 같은열 다른행(친구)를 출력
					{
						cout << relation[1][i] << " ";
						for (int k = 0; k < 5; k++) //친구의 친구
						{
							if (friendArr[relation[1][i]-1][k] == 0) break; //친구없으면 break
							if (friendArr[relation[1][i]-1][k] != cnt) //자신과 친구는 포함x
							{
								cout << friendArr[relation[1][i]-1][k] << " ";
								fcnt++;
							}
						}
					}
					else
					{
						cout << relation[0][i] << " ";
						for (int k = 0; k < 5; k++) //친구의 친구
						{
							if (friendArr[relation[1][i]-1][k] == 0) break; //친구없으면 break
							if (friendArr[relation[1][i]-1][k] != cnt)
							{
								cout << friendArr[relation[1][i]-1][k] << " ";
								fcnt++;
							}
						}
					}
				}
			}
		}
		cout << endl << cnt << "의 최종친구는 총 " << fcnt << "명" << endl;
		cnt++;

	}
	for (int i = 0; i < N; i++)
		delete[] friendArr[i];
	delete[] friendArr;
	return 0;
}
*/
	
/*
cout << "(";
for(int j=0; j<2; j++)
cout << relation[j][i] << " ";
cout << ") ";
*/
// 0 8 14 18 20=\0
	/*문. GeometricObject 베이스 클래스를 설계하라.
	Circle2D, Rectangle2D, MyPoint, Triangle2D 클래스에서 공통된 요소로
	추상 클래스 GeometricObject를 만들고 이를 상속 받은 형태로 클래스를 재정의하라.
	위치, 넓이 구하기 등의 함수를 가상 함수로 정의하라.
	각 클래스를 기존 코드에 적용 시켜서 잘 작동하는지 테스트 하라.
	UML 클래스 다이어 그램도 작성.

		MyPoint point;
	MyPoint point2{10, 30.5};
	Circle2D circle1{ 5, 5, 5 };
	std::cout << point.IsIn(circle1) << std::endl;

	std::cout << "거리: " << point.GetDistance(point2) << std::endl;
	
using namespace std;
void compare(int *str, int n);
int main()
{
	
	int n;
	cout << "입력받을 정수 개수 : ";
	cin >> n;
	cout << "임의 수열 입력 : ";
	int *str = new int[n];
	for (int i = 0; i < n; i++)
		cin >> str[i];
	compare(str, n);
	
	delete[] str;
	return 0;
}
void compare(int *str, int n)
{
	int swap = 0;
	int cnt = 0;
	int loopnum = 0;
	int loopcnt=n-1;
	for (int j = 0; j < n-1; j++)
	{
		if (loopnum == n - 1) break;
		for (int i = n - 1; i > loopnum; i--)//다음부터 loopnum 이하 loop 돌릴 필요 x
		{
			cout << endl;;		//출력부
		/*	for (int i = 0; i < n - loopnum; i++)
				cout << "  ";
			cout << "|" << endl;
			cout << "  ";
			for (int k = 0; k < n; k++) 
				cout << str[i] << " ";
			cout << endl;
			for (int k = 0; k < n; k++)
				cout << "  ";
			cout << "< >" << endl;


			int temp = str[i];
			if (str[i] < str[i - 1])
			{
				str[i] = str[i - 1];
				str[i - 1] = temp;
				loopcnt = i;		//마지막 i 저장
				swap++;
			}
			cnt++;
		}
		loopnum = loopcnt;
	}

	cout << endl;
		for (int i = 0; i < n; i++)
			cout << str[i]<<" ";
		cout << endl << "총 " << cnt << "번 시도" << endl;
		cout << "총 " << swap << "번 교환" << endl;
}
*/
	/*

	dma
		using std::cout;
	using std::endl;

	baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	cout << "baseDMA 객체를 출력한다:\n";
	cout << shirt << endl;
	cout << "lacksDMA 객체를 출력한다.\n";
	cout << balloon << endl;
	cout << "hasDMA 객체를 출력한다.\n";
	cout << map << endl;
	lacksDMA balloon2(balloon);
	cout << "lacksDMA 복사 결과:\n";
	cout << balloon2 << endl;
	hasDMA map2;
	map2 = map;
	cout << "hasDMA 대입결과:\n";
	cout << map2 << endl;
		return 0;
		/////////////////
	userbrass3
		using std::cin;
	using std::cout;
	using std::endl;

	AcctABC *p_client[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "고객의 이름을 입력하십시오: ";
		getline(cin, temp);
		cout << "고객의 계좌 번호를 입력하십시오: ";
		cin >> tempnum;
		cout << "계좌 개설 잔액을 입력하십시오: $";
		cin >> tempbal;
		cout << "Brass 계좌는 1, "
			<< "BrassPlus 계좌는 2를 입력하십시오: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "1 아니면 2, 둘 중 하나를 입력하십시오: ";
		if (kind == '1')
			p_client[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "당좌 대월 한도를 입력하십시오: $";
			cin >> tmax;
			cout << "당좌 대월 이자율을 소수점 형식으로 입력하십시오: ";
			cin >> trate;
			p_client[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_client[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_client[i];
	}
	cout << "프로그램을 종료합니다.\n";
	/////////////////////
	usebrass2
	using std::cin;
	using std::cout;
	using std::endl;
	//use brass2
	Brass *p_client[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "고객의 이름을 입력하십시오: ";
		getline(cin, temp);
		cout << "고객의 계좌 번호를 입력하십시오: ";
		cin >> tempnum;
		cout << "계좌 개설 잔액을 입력하십시오: $";
		cin >> tempbal;
		cout << "Brass 계좌는 1, "
			<< "BrassPlus 계좌는 2를 입력하십시오: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "1 아니면 2, 둘 중 하나를 입력하십시오: ";
		if (kind == '1')
			p_client[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "당좌 대월 한도를 입력하십시오: $";
			cin >> tmax;
			cout << "당좌 대월 이자율을 소수점 형식으로 입력하십시오: ";
			cin >> trate;
			p_client[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_client[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_client[i];
	}
	cout << "프로그램을 종료합니다.\n";
		*/
		/* usebrass1
	Brass Piggy("Porcelot Pigg", 381299, 4000.00);
	BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;
	cout << "Hogg씨의 계좌에 $1000 입금:\n";
	Hoggy.Deposit(1000.00);
	cout << "Hogg씨의 현재 잔액: $" << Piggy.Balance() << endl;
	cout << "Pigg씨의 계좌에서 $4200 인출:\n";
	Piggy.Withdraw(4200.00);
	cout << "Pigg씨의 현재 잔액: $" << Piggy.Balance() << endl;
	cout << "Hogg씨의 계좌에서 $4200 인출: \n";
	Hoggy.Withdraw(4200.00);
	Hoggy.ViewAcct();
	*/

