
#Name: aditi1 gadgul 
#tc014

import subprocess
import os
import shutil
## MOUNTING FILESYSTEM

#make new directory to mount usb filesystem
os.mkdir("mount")

#define all parameters to mount filesystem
source=('/dev/sdb1')
dest=('/home/suppu/mount')
t=('vfat')


#mount the filesystem
subprocess.Popen(["mount","-t",t,source,dest])
print "New mount point is :",dest


#change working directory to new mount point 
#os.chdir("/home/suppu/mount")
#os.mkdir("demo");


## OPERATIONS ON USB FILESYSTEMS
path="/home/suppu/mount"
ip='y'
while ip=='y':
	print "1.Write into file \n 2.Copy file\n 3.Rename \n 4.Delete\n 5.Display file contents "
	n=raw_input("Enter your choice")


	if (n=='1'):
		
		os.chdir(path)
		filename =raw_input("enter the filename to write:")
		fd = open(filename,"w")
		input = raw_input("user input:")
		fd.write(input)
		fd.close()

	if n=='2':
		os.chdir(path)
		#copy files from one place to another
		print "FIles available to copy:"
		os.system("ls")
		cpy=raw_input("Enter which file you want to copy:")
		
		p = raw_input("please enter the path where you want to copy file:")
		shutil.copy(cpy,p);
		os.chdir(p)
		os.system("ls")
	
	if n=='3':
		
		print "contents of demo directory before renaming"
		os.chdir("/home/suppu/mount")
		os.system("ls")
		f1=raw_input("Enter the filename to rename")
		input = raw_input("Enter new fileName:")
		os.rename(f1,input)
		print "contents of demo directory after renaming"
		os.system("ls")

	if n=='4':
		print "contents of demo directory before deletion"
		os.chdir("/home/suppu/mount")
		os.system("ls")
		input = raw_input("Enter file name to delete:")
		os.remove(input)
		print "contents of demo directory After deletion"
		os.chdir("/home/suppu/mount/demo")
		os.system("ls")

	if n=='5':
		os.chdir("/home/suppu/mount")
		print "list of files:"
		os.system("ls");
		f=raw_input("select one file to display contents :")
		fh = open(f, 'r')
		print (fh.read())
		
	ip=raw_input("Do you want to continue?? press y if yes:")
	


"""
OUTPUT:
[aditig@localhost ~]$ python usb_menu.py
1.Write into file 
 2.Copy file
 3.Rename 
 4.Delete
 5.Display file contents 
Enter your choice1
enter the filename to write:try
user input:hello aditi1
Do you want to continue?? press y if yes:y

1.Write into file 
 2.Copy file
 3.Rename 
 4.Delete
 5.Display file contents 
Enter your choice5
list of files:
t2  try
select one file to display contents :try
hello aditi1
Do you want to continue?? press y if yes:y

1.Write into file 
 2.Copy file
 3.Rename 
 4.Delete
 5.Display file contents 
Enter your choice2
FIles available to copy:
t2  try
Enter which file you want to copy:t2
please enter the path where you want to copy file:/home/aditig/aditi1
demo  t2  try

Do you want to continue?? press y if yes:y
 1.Write into file 
 2.Copy file
 3.Rename 
 4.Delete
 5.Display file contents 
Enter your choice3
contents of demo directory before renaming
t2
Enter the filename to renamet2
Enter new fileName:ghdg
contents of demo directory after renaming
ghdg

Do you want to continue?? press y if yes:y
1.Write into file 
 2.Copy file
 3.Rename 
 4.Delete
 5.Display file contents 
Enter your choice4
contents of demo directory before deletion
t1  t2
Enter file name to delete:t1
contents of demo directory After deletion
t2
Do you want to continue?? press y if yes:y

 1.Write into file 
 2.Copy file
 3.Rename 
 4.Delete
 5.Display file contents 
Enter your choice5
list of files:
t2
select one file to display contents :t2
:akjfh
Do you want to continue?? press y if yes:n
[aditig@localhost ~]$ 

"""
	

		


