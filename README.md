Git is a distributed version control system.
Git is free software.
测试管理提交。
i want to become a biggod.
Git 是个非常厉害了版本控制系统。
git checkout --<文件名>，丢弃工作区的修改。
如果已经git add ，想要放弃修改需要两步，1、git reset HEAD <文件名>，
2、git checkout --<文件名>
如果已经commit，参考版本回退。

提交到远程库：git push origin master

查看分支：git branch
创建分支：git branch <文件名>
切换分支：git checkout <文件名>
创建加切换分支：git checkout -b <name>
合并某分支到当前分支：git merge <name>
删除分支：git branch -d <name>

解决冲突
当Git无法自动合并分支时，就必须首先解决冲突。解决冲突后，再提交，合并完成。
解决冲突就是把Git合并失败的文件手动编辑为我们希望的内容，再提交。
用git log --geaph命令可以看到分支合并图。
