#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "bitmap.h"
#include "stego.h"
#include "util.h"

int main(int argc, char **argv) {

	int x=0, intwidth = 0, intheight = 0, status, mode;
	char buffer[17];
	char* message;
	int msglen;
	buffer[0] = 0;
	buffer[16] = '\0';
	char FrameRate[5];
	char width[5];
	char height[5];
	char wxh[10];
	char X[2] = {'x', '\0'};
	char filename[24];
	wxh[9] = '\0';
	width[0] = '0';
	width[4] = '\0';
	height[0] = '0';
	height[4] = '\0';
	FrameRate[0] = '0';
	FrameRate[4] = '\0';
	FILE *text; //opens the text file so we can encode the images ;
	int pipefd[2];
	pipe(pipefd);

	char* input_video, output_video;

	if(strcmp(argv[1], "-e") == 0){
		mode = 0; 
	}else if(strcmp(argv[1], "-d") == 0){
		mode = 1;
	}else{
		printf("wrong arguments");
		exit(0);
	}
	
	if(mode == 0){
		text = fopen(argv[2], "r");
		input_video = strdup(argv[3]);
		output_video = strdup(argv[4]);
	}else if(mode == 1){
		input_video = strdup(argv[2]);
	}
	
	
	char* FFmpegoptions[] = {"usr/bin/ffmpeg","-i", input_video, "-framerate", FrameRate, "-s", wxh, "-f", "image2","Output/foo-%03d.bmp", NULL};

	char* ProbeOptions[] = {"usr/bin/ffprobe", "-v", "error", "-select_streams", "v:0", "-show_entries","stream=width,height,r_frame_rate", "-of", "csv=s=x:p=0", input_video, NULL};

	char* FFmpegCloseOptions[] = {"usr/bin/ffmpeg", "-f", "image2", "-framerate", FrameRate, "-i", "Output/foo-%03d.bmp", "-s", wxh, output_video,"-vcodec", "rawvideo" ,NULL};
	
	
	pid_t pid;
	pid = fork();

	if(pid == 0){ //child process #1
		
		
		close(pipefd[0]); //sets up the pipe so execs output can be read
				  //
		dup2(pipefd[1],1);//
		dup2(pipefd[1],2);//
				  //
		close(pipefd[1]); //
		
		
		execv("/usr/bin/ffprobe", ProbeOptions); //finds the videos frame rate
							
				
	}
	else{ //parent process #1

		close(pipefd[1]);
				
		
		read(pipefd[0], buffer, sizeof(buffer)); //reads output from exec into a buffer
							
	} 
	

	


	//this while loop searches the buffer for the dimensions and framerate and adds them to their own strings
	while(buffer[x] != '\0'){ 
		if(buffer[x] == 'x' && width[0] == '0'){
			memcpy(width, &buffer[0], x);
			memcpy(height, &buffer[x+1], x);
		}
		
		else if(buffer[x] == 'x' && FrameRate[0] == '0'){
			memcpy(FrameRate, &buffer[x+1], 4);
		}
		x++;
	}


	

	strcpy(wxh, width); //copes the width and height into another string for use with ffmpeg
	strcat(wxh, X);
	strcat(wxh, height);	

	
	
	sscanf(width, "%d", &intwidth); //copes the width and height into ints
	sscanf(height, "%d", &intheight);

	

	msglen = intwidth*intheight*3/8; //calculates the length of the message that can be encoded
	message = (char *)malloc(msglen*sizeof(char)); //resizes the message buffer
	message[msglen-1] = '\0'; //gives the message a terminating character so it can be manipulated as a string
	

	pid_t pid1 = fork();
	
	if(pid1 == 0){ //child process #2, this splits the video into images
		execv("/usr/bin/ffmpeg", FFmpegoptions);
	}
	else{
		waitpid(pid1, &status, 0);
	}

	

	for(int a = 0 ; a < 9 ; a++){
		for(int b = 0; b < 9; b++){
			for(int c = 1; c < 9; c++){
				sprintf(filename, "./Output/foo-%d%d%d.bmp", a,b,c);
				if((access(filename, F_OK) != -1)){
					if(mode == 0 && !feof(text) ){
						fgets(message, msglen, text);
						encode(message, filename, filename);
					}else if(mode == 1){
						decode(filename, argv[3]);
					}
				}
			}
		}
	}
	//this for loop creates a filename, checks if that file is accesible, gets a string of size msglen from the file, and encodes it  
	
	if(mode == 0){
		pid_t pid2 = fork();
	
	
		if(pid2 == 0){//child process to recompile the images
			execv("/usr/bin/ffmpeg", FFmpegCloseOptions);
			_exit(0);
		}else{
			waitpid(pid2, &status, 0);
		}
	}

	if(mode == 0) fclose(text);
	free(message);
	printf("exited successfully");
		
	
}
