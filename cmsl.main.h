inline int Addition(int num1,int num2){
	int x=num1^num2;
	int y=num1&num2;
	while(y!=0){
		y=y<<1;
		int temp=x;
		x=x^y;
		y=temp&y;
	}
	return x;
}
