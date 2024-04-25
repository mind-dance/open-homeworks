package com.BookManageSystem.gui.module;
//折叠菜单栏
import javax.swing.*;
import java.awt.*;

import java.util.ArrayList;

public class FoldableMenuBar extends JPanel{
    protected ImageIcon img = new ImageIcon("./logo.jpg");
    protected JLabel logo = new JLabel();
    protected JButton BookManage = new JButton("图书管理");
    protected JButton libraryCard = new JButton("借书证管理");
    protected ArrayList<JButton> buttons = new ArrayList<>();
    protected ArrayList<JButton> temp=new ArrayList<>();
    private static FoldableMenuBar foldableMenuBar = new FoldableMenuBar();
    public static FoldableMenuBar getFoldableMenuBar(){
        return foldableMenuBar;
    }
    private FoldableMenuBar(){
        this.setLayout(new GridLayout(11,1));
        this.setPreferredSize(new Dimension(150, 600));
        img.setImage(img.getImage().getScaledInstance(150, 50,Image.SCALE_FAST));
        logo.setIcon(img);
        this.add(logo,0);
        this.add(BookManage,1);
        buttons.add(BookManage);
        this.add(libraryCard,2);
        buttons.add(libraryCard);
        this.addListener();
    }

    private void addListener(){
        FoldableMenuAction action = new FoldableMenuAction();
        BookManage.addMouseListener(action);
        libraryCard.addMouseListener(action);
    }
}

