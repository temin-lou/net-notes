
# 查看打开游标
    select count(*) from v$open_cursor;
# 创建dba用户
    create user border identified by oraclexxxx;
    grant connect,resource to border;
    select count(*) from v$open_cursor;
    grant dba to border
# 解锁用户
    alter user border accaut unlock;
 



