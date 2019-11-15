#include <stdio.h>
#include <stdlib.h>

int main(){
	float *pv, **ppv, **ppvfr;
	int i,j,m,n; 
	FILE *inptr,*outptr;
	m = 5;
	n = 5; 
	ppv = (float **)malloc(sizeof(float *) * m + sizeof(float) * m * n);
	pv = (float *)(ppv + m);
	ppvfr = ppv;
	printf("0x%x 0x%x \n",pv,ppv);

	for(i = 0; i < m; i++) {
		ppv[i] = (pv + m * i);
		printf("0x%x 0x%x \n",pv,ppv[i]);		 
	}
	
	for (j=0;j<m;j++) {
		for (i=0;i<n;i++) {
			ppv[i][j] =(float)(i+j);
			printf("i=%d j=%d %5.3f 0x%x\n",i,j,ppv[i][j],&ppv[i][j]);
		}
	}
	
	outptr = fopen("doubleptr.bin","w");
	if (outptr !=0) {
		fwrite(pv,sizeof(float),m*n,outptr);
		fclose(outptr);
	}
	else {
		printf("could not open file for writing\n");
	}
	/*
	* fid = fopen('doubleptr.bin','r'); mat55 = fread(fid, [5,inf], 'float');
	* [U S V] = svd(mat55);
	* rcmat55 = U*S*V';
	*/ 
	free(ppvfr);
	return 0;
	}
