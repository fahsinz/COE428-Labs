void mySort(int d[], unsigned int n)
{
	unsigned int i,j, tempnum;
	
	for (i=0; i<n; i++){
		for (j=0; j<n-1;j++){
			if (d[j]>d[j+1]){
				tempnum = d[j];
				d[j] = d[j+1];
				d[j+1] = tempnum;}
			}	
		}
}
