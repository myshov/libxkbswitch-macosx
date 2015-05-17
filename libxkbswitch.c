// Libxkbswitch - Mac OS X library for vim-xkbswitch
//
// The MIT License (MIT)
//
// Copyright (c) 2015 Alexander Myshov
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#import "stdio.h"
#import "string.h"
#import "stdlib.h"
#import "libxkbswitch.h"


const char * Xkb_Switch_setXkbLayout( const char * param ) {
    char command[100] = "";
    strcat(command, "/usr/local/bin/xkbswitch -s ");
    strcat(command, param);
    
    system(command);
    
    return "";
}

const char * Xkb_Switch_getXkbLayout( const char * param ) {
    FILE *fp;
    static char result[100];
    
    fp = popen("/usr/local/bin/xkbswitch -g", "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }
    
    fgets(result, sizeof(result)-1, fp);
    pclose(fp);
    return result;
}