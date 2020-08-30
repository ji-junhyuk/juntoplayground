### if you want to install from source, first install all of the dependencies :
$sudo apt-get install libcurl4-gnutls-dev libexpat1-dev gettext
refer : 

### Git environment Setup
1. /etc/gitconfig file : every user on the system and all their repository
2. ~/.gitconfig or ~/.config/git/config file : specific to your user
3. config file in the Git directory .git/config : you're currently using sing repository
refer : 

#### step 1: identity:
$ git config --global user.name "John Doe"
$ git config --global user.email "johndoe@example.com"

#### step 2: editor:
$ git config --global core.editor emacs

#### step 3: checking your setting:
$ git config --list

#### step 4: Getting help
$ git help         
$ git help <verb
///refer: github channel>

### Getting a git repository

#### initializing a repository in an existing directory
$ git init

begin tracking
$ git add *.c
$ git commit -m "initial project version"

#### Cloning an existing repository
$ git clone [url] // local repo name : [url] name
$ git clone [url] [project 1] // local repo name : [project 1] 

### file status : 
tracked / untracked
unmodified / modified / staged

### 
git status 
git status -s (-s : --short)

git diff
$ git diff --staged
$ git diff --cached

### .gitignore 
refer : https://github.com/github/gitignore
git rm --cached -> Not understand well

### commit 
$ git commit -m "Story 182: Fix benchmarks for speed"
-a : skipping staging area

### mv
rename , move 

### git log 
-p -2 // very helpful code review or quickly browse
--stat
--pretty=oneline  
$ git log --pretty=format:"%h - %an, %ar : %s"
%H Commit hash 
%h Abbreviated commit hash
%T Tree hash 
%t Abbreviated tree hash 
%P Parent hash 
%p Abbreviated parent hash 
%an Author name 
%ae Author e-mail 
%ad Author date (format respects the –date= option 
%ar Author date, relative 
%cn Committer name 
%ce Committer e-mail 
%cd Committer date 
%cr Committer date, relative 
%s Subject
+option --graph
$ git log --pretty=format:"%h %s" --graph

-p Show the patch introduced with each commit.
--stat Show statistics for files modified in each commit. 
--shortstat Display only the changed/insertions/deletions line from the --stat command. 
--name-only Show the list of files modified after the commit information. 
--name-status Show the list of files affected with added/modified/deleted information as well. 
a-abbrev-commit Show only the first few characters of the SHA-1 checksum instead of all 40. 
--graph Display an ASCII graph of the branch and merge history beside the log output. 
--pretty Show commits in an alternate format. Options include oneline, short, full, fuller, and format (where you specify your own format).

--relative-date Display the date in a relative format (for example, “2 weeks ago”) instead of using the full date

### reset without option, not danger (only touch local repo)

### git checkout -- command is danger // any changes you made that files are gone, copy over it

### git remote
git remote -v
git remote add [remote-name] [url]
git fetch [name] 
git fetch [remote-name]i

git push [remote-name] [branch-name].
$git push origin master

$ git remote rename pb paul

$ git remote rm paul

$ git tag v0.1
$ git tag -l v0.1

###creating tag
lightweight tag : To create a lightweight tag, don’t supply the -a, -s, or -m option:

annotated tag

$ git tag -a v1.4 -m 'my version 1.4'
$ git show v1.4

$ git --log pretty=oneline

$ git tag -a v1.2 9fceb02
$ git tag
$ git show v1.2

$ git push origin v1.5
$ git push origin --tags

### Git Aliases

$ git config --global alias.co checkout
$ git config --global alias.br branch
$ git config --global alias.ci commit
$ git config --global alias.st status
$ git config --global alias.unstage 'reset HEAD --'
 =$ git config --global alias.unstage 'reset HEAD --'
 =$ git reset HEAD fileA

$git config --global alias.last 'log -1 HEAD'
 =$ git last

$git config --global alias.visual "!gitk"

### branch
$git branch "branchName"
$git log --oneline --decorate

$git checkout "branchName"
$git log --oneline --decorate --graph --all

$ git checkout -b iss53

$ git mergetool

$ git branch --merged, --no-merged

$ git branch -D testing ( if you wanna delete branc that work)

& git checkout --track origin/

& git config --global credential.helper cache

$ git branch -u origin/serverfix

$ git branch -vv

$ git fetch --all; git branch -vv

$ git push origin --delete serverfix

$ git rebase master

$ git rebase --onto master server client

$ git rebase master server

