#pragma once
#include <stdio.h>
#include <stdlib.h>


//定义书本Book的结构体
typedef struct Node {
	int id;				//编号
	char name[50];		//书名
	char author[20];	//作者
	int inventory;		//库存量
	float price;		//价格
	struct Node* next;	//指针域
} Book;	//结构体定义为Book

//选择功能
void choose();
//打印菜单
void printMainMenu();
//创建链表模块
Book *create(Book *);
//删除节点模块
void del(Book*);
//插入节点模块（可多个插入）
void insert(Book*);
//修改节点模块
void mod(Book *);
//输出链表函数
void printBook(Book *);
//打印搜索菜单
void printSearchnMenu();
//根据作者查询
void searchByAuthor(Book*);
//根据编号查找图书信息
void searchById(Book*);
//根据书名查找图书信息
void searchByName(Book*);
//链表根据编号排序（冒泡排序）
void sortById(Book*);

int main() {
	//选择功能
	choose();

	return 0;
}

//选择功能
void choose() {
	Book* head = NULL;
	int flag;	//控制主菜单功能
	int i = 1;		//控制循环,以-1终止

	while (i > 0) {
		printMainMenu();	//打印菜单
		scanf_s("%d", &flag);//选择功能

		switch (flag) { //各操作数字对应菜单数字，通过n确定操作类型
		case 1://创建
			head = create(head);
			sortById(head);	//排序
			break;
		case 2://插入
			insert(head);
			break;
		case 3://删除
			del(head);
			break;
		case 4://修改
			mod(head);
			break;
		case 5://查找
			printSearchMenu();	//打印查询菜单
			int flagSerch = 0;	//控制查询菜单功能
			scanf_s("%d", &flagSerch);
			switch (flagSerch) {
			case 1:	//查询所有图书信息
				printBook(head);
				break;
			case 2:	//根据编号查询
				searchById(head);
				break;
			case 3:	//根据书名查询
				searchByName(head);
				break;
			case 4:	//根据作者查询
				searchByAuthor(head);
				break;
			defalt:	//返回主菜单
				break;
			}
			break;
		default:
			i = -1;	//跳出循环，退出管理系统
			printf("\n成功退出管理系统！\n\n");
			printf("按任意字符关闭窗口");
			getch();
			break;
		}	
	}
}

//打印菜单
void printMainMenu() {
	system("cls");		// 清屏
	system("color 71");	//设置字体和背景颜色
	putchar('\n');
	printf("\t\t图书信息管理系统\t\n");	
	printf("\t ============================\n");
	printf("\t ｜\t作者：author       ｜\n");
	printf("\t ｜\t学号：number       ｜\n");
	printf("\t ============================\n");
	printf("\t ｜\t1.图书链表创建     ｜\n");
	printf("\t ｜\t2.图书信息插入     ｜\n");
	printf("\t ｜\t3.图书信息删除     ｜\n");
	printf("\t ｜\t4.图书信息修改     ｜\n");
	printf("\t ｜\t5.图书信息查询     ｜\n");
	printf("\t ｜\t6.退出管理系统     ｜\n");
	printf("\t ============================\n");
	printf("\t请选择功能模块(1～6,按其他字符退出):");

}

//创建链表模块
Book* create(Book *head) {
	system("cls");			//清空屏幕
	if (!head) {	//如果不存在链表，创建链表
		Book* p, * q;	//定义指针
		head = (Book*)malloc(sizeof(Book));	//从头节点开辟空间
		head->next = NULL;	//置空头节点的指针域
		q = head;			//q指针记录头节点的地址
		p = head->next;	//p指针记录头节点的指针域的地址

		printf("请输入书本的信息,按-1结束（格式：编号 书名 作者 库存量 价格）\n");
		int id;	//输入的编号
		scanf_s("%d", &id);

		while (id != -1) {
			p = (Book*)malloc(sizeof(Book));	//p指针开辟空间
			//输入各成员
			p->id = id;
			scanf("%s %s %d %f", p->name, p->author, &p->inventory, &p->price);
			p->next = NULL;	//置空p节点的指针域
			q->next = p;	//p，q节点连接
			q = p;			//q指针后移
			printf("请输入书本的信息，按-1结束（格式：编号 书名 作者 库存量 价格）\n");
			scanf_s("%d", &id);
		}
	}
	else {	//如果存在链表，返回错误信息
		printf("已存在图书链表，请勿重复创建!\n");
		//使页面停留在当前页
		printf("输入任意键返回......");
		getch();
	}

	return head;	//返回链表的起始位置
}

//删除节点模块
void del(Book* head) {
	system("cls");
	//如果链表不为空，开始删除
	if (head) {
		Book* p, * q;//定义指针
		int id;//用于输入编号查找删除
		p = head;//p记录头节点的地址
		q = head->next;//q记录头节点的指针域的地址
		printf("请输入要删除的图书编号：");
		//输入编号
		scanf_s("%d", &id);
		while (q != NULL) { //q不为空时执行循环
			if (q->id == id)//判断是否找到输入的编号
				//为真时
			{
				p->next = q->next;//断开q节点
				free(q);//释放q节点neicun
				q = NULL; //置空q指针防止出现野指针
			}
			else {
				//判断为假时
				p = p->next;//p指针后移
				q = q->next;//q指针后移
			}
		}
		//当查找到最后一个节点还未查到要删除的编号时，输出错误信息
		if (p == NULL) {
			printf("没有此编号\n");
			//使页面停留在当前页
			printf("输入任意键返回......");
			getch();
		}
	}
	//如果链表为空
	else {
		printf("还未创建图书链表，请创建链表后再删除\n");
		//使页面停留在当前页
		printf("输入任意键返回......");
		getch();
	}
	
}

//插入节点模块（可多个插入）
void insert(Book *head) {
	system("cls");

	//如果链表不为空，开始插入
	if (head) {
		int flag = 1;	//flag实现判断指针是否到达最后一个节点

		Book* p, * q, * r;	//定义指针便于插入操作
		printf("请输入书本的信息,按-1结束（格式：编号 书名 作者 库存量 价格）\n");

		int id;	//输入的编号
		scanf_s("%d", &id);

		while (id != -1) {	//输入-1结束
			r = (Book*)malloc(sizeof(Book));	//r指针开辟空间
			r->next = NULL;	//置空r的指针域
			r->id = id;
			scanf("%s %s %d %f", r->name, r->author, &r->inventory, &r->price);

			q = head;//q指针记录头节点的地址
			p = head->next;//p指针记录头节点的指针域的地址
			while (q->next != NULL && p->id < r->id) { //循环条件：当q->next不为空,以及按图书编号排序插入
				p = p->next;//p指针后移
				q = q->next;//q指针后移
				if (q->next == NULL) { //这个判断防止q->next为空时，在执行循环是出现野指针使程序出错
					p = NULL;//防止出现野指针p
					q->next = r;//连接节点
					r->next = NULL;//置空r指针域
					flag = 0;//到达最后一个节点更改flag
					break;
				}
			}
			if (flag) { //判断是否到达最后一个节点，为真执行该操作
				r->next = p;
				q->next = r;
				//实现将r节点插入链表
			}
			printf("请输入书本的信息,按-1结束（格式：编号 书名 作者 库存量 价格）\n");
			scanf_s("%d", &id);
		}
	}
	//如果链表为空
	else {
		printf("还未创建图书链表，请创建链表后再插入!\n");
		//使页面停留在当前页
		printf("输入任意键返回......");
		getch();
	}
	

}


//修改节点模块
void mod(Book* head) {
	system("cls");
	//如果链表不为空，开始修改
	if (head) {
		Book* p;	//定义指针
		int id1, id2, inventory1;	//定义num1用于输入查找书籍修改信息,num2用于修改
		char name1[50], author1[20];
		float price1;
		printf("请输入要修改的图书编号：");
		//输入要修改的图书编号
		scanf_s("%d", &id1);
		p = head->next;
		while (p != NULL) {
			if (p->id == id1) {		//判断是否找到书籍
				printf("请输入书本的信息（格式：编号 书名 作者 库存量 价格）\n");
				//为真时，重输图书信息
				scanf("%d %s %s %d %f", &id2, name1, author1, &inventory1, &price1);
				p->id = id2;
				strcpy(p->name, name1);
				strcpy(p->author, author1);
				p->inventory = inventory1;
				p->price = price1;
				break;
			}
			else {
				//为假时
				p = p->next;//指针后移
			}
		}
		if (p == NULL) {//查找到最后一个节点还未查到要的编号时，输出错误信息
			printf("未查找到该图书编号\n");
			//使页面停留在当前页
			printf("输入任意键返回......");
			getch();
		}
	}
	else {
		printf("还未创建图书链表，请创建链表后再修改!\n");
		//使页面停留在当前页
		printf("输入任意键返回......");
		getch();
	}

}

//输出链表函数
void printBook(Book *head) {
	system("cls");		// 清屏
	//如果链表不为空，显示信息
	if (head) {
		Book* p = head->next;
		printf("编号\t书名\t作者\t数量\t价格\n");
		while (p) { //当p不为空的时候执行
			printf("%d\t%s\t%s\t%d\t%.2f\n", p->id, p->name, p->author, p->inventory, p->price);
			printf("\n");
			p = p->next;//指针后移
		}
	}
	//如果为空
	else {
		printf("还未创建图书链表，请添加书本后再查询!\n");
	}

	//使页面停留在当前页
	printf("输入任意键返回......");
	getch();
}

//打印搜索菜单
void printSearchMenu() {
	system("cls");		// 清屏
	system("color 71");	//设置字体和背景颜色

	putchar('\n');
	printf("\t\t图书信息管理系统\t\n");
	printf("\t ============================\n");
	printf("\t\t  图书信息查询\t\n");
	printf("\t ============================\n");
	printf("\t ｜\t1.查询所有图书信息 ｜\n");
	printf("\t ｜\t2.根据编号查询     ｜\n");
	printf("\t ｜\t3.根据书名查询     ｜\n");
	printf("\t ｜\t4.根据作者查询     ｜\n");
	printf("\t ｜\t5.返回主菜单       ｜\n");
	printf("\t ============================\n");
	printf("\t请选择功能(1～5,按其他字符退出):");

}

//根据作者查询
void searchByAuthor(Book* head) {
	system("cls");		// 清屏

	//如果链表不为空，开始查询
	if (head) {
		Book* p;//定义指针
		char author[20];//定义author用于输入查找书籍
		printf("请输入您要查找图书的作者:");
		//输入查找作者
		scanf("%s", author);
		p = head->next;
		while (p != NULL) {
			if (strcmp(p->author, author) == 0) { //判断是否找到书籍
				//为真时，输出信息
				printf("书籍信息\n");
				printf("编号\t书名\t作者\t数量\t价格\n");
				printf("%d\t%s\t%s\t%d\t%.2f\n", p->id, p->name, p->author, p->inventory, p->price);
				break;
			}
			else
				//为假时
				p = p->next;//指针后移
		}
		if (p == NULL) {	//查找到最后一个节点还未查到要的编号时，输出错误信息
			printf("未查询到该图书！\n");
		}
	}
	//如果为空
	else {
		printf("还未创建图书链表，请添加书本后再查询!\n");
	}

	//使页面停留在当前页
	printf("输入任意键返回......");
	getch();
}

//根据编号查找图书信息
void searchById(Book* head) {
	system("cls");		// 清屏
	//如果链表不为空，开始查询
	if (head) {
		Book* p;//定义指针
		int id1;//定义id1用于输入查找书籍
		printf("请输入您要查找的图书编号:");
		//输入查找编号
		scanf_s("%d", &id1);
		p = head->next;
		while (p != NULL) {
			if (p->id == id1) { //判断是否找到书籍
				//为真时，输出信息
				printf("编号\t书名\t作者\t数量\t价格\n");
				printf("%d\t%s\t%s\t%d\t%.2f\n", p->id, p->name, p->author, p->inventory, p->price);
				break;
			}
			else
				//为假时
				p = p->next;//指针后移
		}
		if (p == NULL)//查找到最后一个节点还未查到要的编号时，输出错误信息
			printf("未查询到该图书！\n");
	}
	//如果为空
	else {
		printf("还未创建图书链表，请添加书本后再查询!\n");
	}

	//使页面停留在当前页
	printf("输入任意键返回......");
	getch();
}

//根据书名查找图书信息
void searchByName(Book* head) {
	system("cls");		// 清屏
	
	//如果链表不为空，开始查询
	if (head) {
		Book* p;//定义指针
		char name1[50];//定义name1用于输入查找书名
		printf("请输入您要查找的书名:");
		//输入查找书名
		scanf("%s", name1);
		p = head->next;
		while (p != NULL) {
			if (strcmp(p->name, name1) == 0) { //判断是否找到书籍
				//为真时，输出信息
				printf("编号\t书名\t作者\t数量\t价格\n");
				printf("%d\t%s\t%s\t%d\t%.2f\n", p->id, p->name, p->author, p->inventory, p->price);
				break;
			}
			else {
				//为假时
				p = p->next;//指针后移
			}
		}
		if (p == NULL) {	//查找到最后一个节点还未查到要的编号时，输出错误信息
			printf("未查询到该图书！\n");
		}
	}
	//如果为空
	else {
		printf("还未创建图书链表，请添加书本后再查询!\n");
	}

	//使页面停留在当前页
	printf("输入任意键返回......");
	getch();
}

//链表根据编号排序（冒泡排序）
void sortById(Book* head) {
	//排序中没有修改头节点指针值，只是修改指针内容head->next的值
	Book* pre, * p, * tail, * temp;
	tail = NULL;
	pre = head;
	while ((head->next->next) != tail) { //(head->next)!=tail同样适用 ，多执行最后一个步比较
		p = head->next;
		pre = head;
		while (p->next != tail) {
			if ((p->id) > (p->next->id)) {
				pre->next = p->next; //交换节点方法
				temp = p->next->next;
				p->next->next = p;
				p->next = temp;
				p = pre->next;  //p回退一个节点
			}
			p = p->next;  //p再前进一个节点
			pre = pre->next;
		}
		tail = p;
	}
}
