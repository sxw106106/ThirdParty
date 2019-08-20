#include <stdio.h>
#include <curl.h>
#include <fcntl.h>
#include <stdlib.h>

int OnDebug( CURL* crl, curl_infotype itype, char * pData, size_t size, void * p)
{
	printf("OnDebug\n");
}

static size_t OnWriteData( void *ptr, size_t size, size_t nmemb, void *stream)
{
	printf("OnWriteData\n");
	fwrite(ptr, size, nmemb, (FILE*)stream);
	return nmemb * size;
}

int url_get(const char* url, void *p)
{
	printf("in=================%s,===%s,===%d行\n",__FILE__,__FUNCTION__,__LINE__);
	CURLcode res;
	CURL* curl = curl_easy_init();
	if ( NULL == curl )
	{
		printf( "Info[%s] : CURLE_FAILED_INIT.\n", __FUNCTION__ );
		printf("in=================%s,===%s,===%d行\n",__FILE__,__FUNCTION__,__LINE__);
		return CURLE_FAILED_INIT;
	}
	//curl_easy_setopt( curl, CURLOPT_VERBOSE, 1 );
	//curl_easy_setopt( curl, CURLOPT_DEBUGFUNCTION, OnDebug );
	curl_easy_setopt( curl, CURLOPT_URL, url);
	curl_easy_setopt( curl, CURLOPT_READFUNCTION, NULL );
	curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, OnWriteData );
	curl_easy_setopt( curl, CURLOPT_WRITEDATA, p);
	/**
	* 当多个线程都使用超时处理的时候，同时主线程中有sleep或是wait等操作。
	* 如果不设置这个选项，libcurl将会发信号打断这个wait从而导致程序退出。
	*/
	curl_easy_setopt( curl, CURLOPT_NOSIGNAL, 1 );
	curl_easy_setopt( curl, CURLOPT_CONNECTTIMEOUT, 10);
	curl_easy_setopt( curl, CURLOPT_TIMEOUT, 10 );
	res = curl_easy_perform( curl );
	curl_easy_cleanup( curl );
	printf("in=================%s,===%s,===%d行\n",__FILE__,__FUNCTION__,__LINE__);
	return res;
}


int main()
{
	curl_global_init(CURL_GLOBAL_ALL);
	
	//char *url = "http://isure.stream.qqmusic.qq.com/C2000004zcfr0neC9O.m4a?guid=2000001576&vkey=A8342FCB3D1C208FFC09690FB116AF312DB90A5911806BB5E311CCE520ACDAA26E239B6767FE6CEB39672FBEED28EA7BE90CEA11ADC62245&uin=&fromtag=50";
	char *url = "https://www.baidu.com/";
	FILE *pfile = fopen("a.html", "wb");
	if(pfile == NULL) {
		printf("open error\n");
		return 0;
	}
	
	url_get(url, pfile);
	fclose(pfile);
	printf("%s\n", curl_version());
	curl_global_cleanup();
	return 0;
}
