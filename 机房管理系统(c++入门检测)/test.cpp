/*机房管理系统
1.分为三类 ： 学生  老师  管理员

学生的功能 ： 预约机房 取消预约 查看本身预约 登录 退出
老师的功能 ： 查看预约 审核预约 登录 退出
管理员的功能 ： 添加账号 删除账号 查看学生信息 查看机房信息 清空预约 登录 退出(设计一个)

*/

#include<iostream>
#include"Scene.h"

using namespace std;

//嵌套显示
int main()
{
	Scene scene;
	
	int choice;

	while (1)
	{
		scene.signIn();

		switch (choice)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
			break;
		default:
			break;
		}
	}

	return 0;
}