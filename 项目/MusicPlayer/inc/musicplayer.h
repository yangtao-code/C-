#pragma once

#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdbool.h>
#include "ts.h"
#include "lcd.h"
#include "linklist.h"
#include <pthread.h>

#define FIFONAME "mplayer_fifo"

// 音乐的播放状态
typedef enum
{
    STAT_OFF = 0, // 未播放
    STAT_ON = 1,  // 正在播放
    STAT_STOP = 2 // 暂停
} MUSIC_STAT;


// 音乐播放器
class MusicPlayer : public Ts, public Lcd
{
public:
    MusicPlayer();
    ~MusicPlayer();
    // 音乐播放器的主界面
    void mplayer();

    // 播放MP3音乐
    void play_mp3();
    // 播放MP4视频
    void play_mp4();

    // mp3音乐播放器的选择操作,返回-1为退出当前播放器
    int option_mp3();
    // mp4音乐播放器的选择操作,返回-1为退出当前播放器
    int option_mp4();

    /***********************************
    音乐播放器的各种操作函数,如播放下一首,上一首,
    暂停/开始,快进,后退,返回,退出
    ************************************/
    void play_next_music(int m);
    void play_prev_music(int m);
    void stop_or_play_music(int m);
    void back_music();
    void forwark_music();
    void return_music();
    void quit_mplayer();

    //  读取MP3目录下的mp3文件将其存放到filenames_mp3
    void readdir_mp3();
    // 读取MP4目录下的mp4文件将其存放到filenames_mp4
    void readdir_mp4();

    // 退出程序接口
    void exit_mplayer();
    // 线程函数,不断获取触摸状态
    static void *GetState(void *arg);
    // 初始化管道文件,向mplayer发送指令
    void init_fifo(string fifo_name);

    // 向管道写指令,返回0为成功,返回-1为失败
    int write_cmd(string cmd);

    // 信号处理函数
    // static void signal_handler(int signo);

    /******************************
        音乐播放器的各种状态参数
    ******************************/
    pthread_t state_pid;      // 触摸状态获取的线程id
    Linklist filenames_mp3;   // 存放MP3文件的文件路径
    Linklist filenames_mp4;   // 存放MP3文件的文件路径
    Node *work_mp3;           // MP3音乐的工作指针,指向正在播放的音乐
    Node *work_mp4;           // MP4视频的工作指针,指向正在播放的视频
    MUSIC_STAT mplayer_state; // 音乐播放状态
    int Current_music_player; // 当前播放音乐的格式,0为没有播放音乐,1为mp3音乐,为mp4音乐
    int fifo_fd;              // 管道的文件描述符
};