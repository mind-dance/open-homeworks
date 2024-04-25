package com.BookManageSystem.gui.module;
//侧边折叠面板
import java.awt.event.*;
import javax.swing.*;

public class FoldableMenuAction extends MouseAdapter{
    @Override
    public void mouseClicked(MouseEvent e) {

        for( JButton button: FoldableMenuBar.getFoldableMenuBar().temp){
            FoldableMenuBar.getFoldableMenuBar().remove(button);
        }
        //将菜单清空
        FoldableMenuBar.getFoldableMenuBar().temp.clear();

        //复原菜单
        FoldableMenuBar.getFoldableMenuBar().temp.addAll(FoldableMenuBar.getFoldableMenuBar().buttons);
        if (e.getSource() == FoldableMenuBar.getFoldableMenuBar().BookManage){
            //为图书管理添加菜单项
            FoldableMenuBar.getFoldableMenuBar().temp.add(1,FoldableMenuItem.getFoldableMenuItem().addBook);
            FoldableMenuBar.getFoldableMenuBar().temp.add(2,FoldableMenuItem.getFoldableMenuItem().queryBook);
        }
        if (e.getSource() == FoldableMenuBar.getFoldableMenuBar().libraryCard){
            //为借书卡管理添加菜单项
            FoldableMenuBar.getFoldableMenuBar().temp.add(2,FoldableMenuItem.getFoldableMenuItem().enrollCard);

        }


        //生成新菜单
        int i=1;
        for (JButton button: FoldableMenuBar.getFoldableMenuBar().temp) {
            FoldableMenuBar.getFoldableMenuBar().add(button,i++);
        }
        //更新窗口
        FoldableMenuBar.getFoldableMenuBar().updateUI();
    }

}