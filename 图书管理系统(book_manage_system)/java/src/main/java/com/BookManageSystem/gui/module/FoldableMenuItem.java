package com.BookManageSystem.gui.module;
//折叠侧边栏的主要按钮
import com.BookManageSystem.util.StyleUtil;
import com.BookManageSystem.gui.action.*;
import javax.swing.*;

public class FoldableMenuItem {

    //新的菜单项
    public JButton addBook = new JButton("添加图书");
    public JButton queryBook = new JButton("查询图书");
    public JButton enrollCard = new JButton("借书证注册");

    public JButton reviseCode = new JButton("修改密码");

    private static FoldableMenuItem menuItem = new FoldableMenuItem();
    public static FoldableMenuItem getFoldableMenuItem(){
        return menuItem;
    }
    private FoldableMenuItem(){
        this.buttonStyle();
        this.addAction(addBook,queryBook,enrollCard,reviseCode);
    }
    private void buttonStyle(){
        //使按钮透明
        StyleUtil.buttonStyle(addBook,queryBook,enrollCard,
                reviseCode);
    }

    private void addAction(JButton ... buttons){
        SwitchAction switchAction =new SwitchAction();
        for ( JButton button: buttons) {
            button.addMouseListener(switchAction);
        }
    }
}
