package com.BookManageSystem.entity.user;
//屎山代码，用于定义用户级别，在本项目中已删除。为了防止软件崩溃，故保留。

public interface UserPower {
    final static int SUPERMANAGER=10;
    final static int MANAGER=7;
    final static int VIPUSER=5;
    final static int USER=1;
    public int getPower();
}
