#include <stdio.h>
//#include "librtmp_send264.h"
#include "librtmp_sendAAC.h"
#include "rtmp_net.h"


FILE *fp_send1;

//���ļ��Ļص�����
//we use this callback function to read data from buffer
int read_buffer1(unsigned char *buf, int buf_size ){
	if(!feof(fp_send1)){
		int true_size=fread(buf,1,buf_size,fp_send1);
		return true_size;
	}else{
		return -1;
	}
}

//#include<windows.h>

int main(int argc, char* argv[])
{
	//fp_send1 = fopen("cuc_ieschool.h264", "rb");
	
	//��ʼ�������ӵ�������
	Net_Init("rtmp://192.168.0.5:1935/live");
	//����
	RTMPAAC_Send();
	//RTMP264_Send(read_buffer1);
	//�Ͽ����Ӳ��ͷ������Դ
	Net_Close();

	return 0;
}

