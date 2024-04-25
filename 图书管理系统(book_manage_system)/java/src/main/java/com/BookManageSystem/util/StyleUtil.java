package com.BookManageSystem.util;

import javax.swing.*;
//按钮样式控制
public class StyleUtil {
    private StyleUtil(){}
    public static void buttonStyle(JButton... buttons){
        //是按钮变为透明
        for (JButton button:buttons) {
            button.setContentAreaFilled(false);
        }
    }

}
