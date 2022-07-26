#include <iostream>
#include <cstdlib>

using namespace std;

void next(int *path[], int stepi, int stepj, int height, int width, bool& end, int *maze[], int &pathi);


int main(void)
{
	int **maze, **path;
	int height, width;
	int i, j, pathi = 0;
	char flag = 'y';
	cout << "Enter the height of maze => ";
	cin >> height;
	if (height < 2) {
		cout << "The data is error";
		system("pause");
		exit(1);
	}
	height += 2;
	cout << "Enter the width of maze => ";
	cin >> width;
	if (width < 2) {
		cout << "The data is error";
		system("pause");
		exit(1);
	}
	width += 2;
	/* 宣告迷宮陣列*/
	maze = new int*[height];
	/* 宣告路徑陣列(追蹤)*/
	path = new int*[height*width];
	for (int i = 0; i < height; i++) {
		maze[i] = new int[width];
		for (int j = 0; j < width; j++) {
			maze[i][j] = 0;
		}
	}
	for (int i = 0; i < height*width; i++) {
		path[i] = new int[2];
	
	}
	/* 設置牆壁 */
	for (int i = 0; i < width; i++) {
		maze[0][i] = 1;
		maze[height - 1][i] = 1;
	}
	for (int i = 0; i < height; i++) {
		maze[i][0] = 1;
		maze[i][width - 1] = 1;
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout.width(3);
			cout << maze[i][j];
		}
		cout << endl;
	}
	do {
		cout << "Enter the maze's wall, (1,1),(" << height - 1 << "," << width - 1 << ") is start and finish" << endl;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cout.width(3);
				cout << maze[i][j];
			}
			cout << endl;
		}
		cout << "Enter the target row(1~" << height - 1 << ") => ";
		cin >> i;
		if (i<1 || i>height - 1) {
			cout << "The data is error";
			system("pause");
			exit(1);
		}
		cout << "Enter the target col(1~" << width - 1 << ") => ";
		cin >> j;
		if (j<1 || j>width - 1) {
			cout << "The data is error";
			system("pause");
			exit(1);
		}
		if (i == 1 && j == 1) {
			
		}
		else if (i == height - 2 && j == height - 2) {

		}
		else {
			maze[i][j] = 1;
		}
		cout << "Do you want to continue add wall (y or n)=> ";
		cin >> flag;
	} while (flag == 'Y' || flag == 'y');
	/* 開始走迷宮*/
	bool end = false;
	next(path, 1, 1, height, width, end, maze, pathi);
	if (end == true) {
		cout << "The rat success" << endl;
		cout << "The road's lenth is " << pathi;
	}
	else {
		cout << "The rat cannot find the finish point ";
	}


	system("pause");
	return(0);
}

void next(int *path[], int stepi, int stepj, int height, int width, bool& end, int *maze[], int &pathi) {
	
	if (end) {
		return;
	}
	else if (stepi == height - 1 && stepj == width - 1) {
		cout << "(" << stepi << "," << stepj << ")" << endl;
		end = true;
		return;/*結束函式*/
	}
	else if (maze[stepi][stepj] == 1) {
		return;
	}
	else {
		cout << "(" << stepi <<","<< stepj << ")" << endl;
		maze[stepi][stepj] = 1;
		path[pathi][0] = stepi;
		path[pathi][1] = stepj;
		pathi++;
		next(path, stepi + 1, stepj + 1, height, width, end, maze, pathi);//右下
		next(path, stepi - 1, stepj, height, width, end, maze, pathi);//上
		next(path, stepi + 1, stepj, height, width, end, maze, pathi);//下
		next(path, stepi, stepj - 1, height, width, end, maze, pathi);//左
		next(path, stepi, stepj + 1, height, width, end, maze, pathi);//右
		next(path, stepi - 1, stepj + 1, height, width, end, maze, pathi);//右上
		next(path, stepi - 1, stepj - 1, height, width, end, maze, pathi);//左上
		next(path, stepi + 1, stepj - 1, height, width, end, maze, pathi);//左下
		
		/*若沒有找到終點，向後一格改走其他路*/
		if (!end)
		{
			maze[stepi][stepj] = 0;
			pathi--;
		}
	}
}