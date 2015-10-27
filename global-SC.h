/**********************************************/
/*此文件是标定-校正参数文件，所有输入的参数放在该文件中*/
/**********************************************/
#pragma once
const int successes_ideal=6; //表示每个相机所拍得的用来标定的棋盘格图片的个数
const int board_w=6;           //表示棋盘格高的内角点的个数
const int board_h=8;           //表示棋盘格宽的内角点的个数
const int board_n=board_w*board_h; //棋盘格的总数
const int camera_num=2;        //表示标定的相机的个数
const int corner_width=50;     //表示棋盘格标定板的宽为50mm  

