% Git
% Drew Helgerson
% Apr. 22, 2024

# What is Git/GitHub

## What git is not
- Git is not GitHub!
- Git is not Dropbox!
- Git is not any kind of web-service!

## The problem Git solves/ What is versioning
- scenario of versioning headaches
- Hook: what if it was easier
- change-based versioning
- snapshot-based versioning

## Real Definition
git is a command-line, snapshot-based versioning tool
- created by Linux Torvalds to manage massive open source projects. i.e. the Linux kernel
- used widely across the globe, for personal and enterprise use

# How do we use it

## Cloning a Repo
- `git clone <repo>.git`

# Creating a Repo
## Local 
first create a local Repo
- `cd /path/to/project/dir`
- `git init -b <branch-name>`
- add any files you don't want to be kept track of to `.gitignore`
- `git stage .`
- `git commit`

## Remote 
now push your Repo to a remote
- Create a Repo on your desired remote(GitHub)
- `git add remote origin <remote repo>.git`
- now to sync your local repo with the remote repo do: `git pull && git push`

## Commits
- the backbone of git
- creates a snapshot in time of your project and hashes it for computation
- **after any meaningful change, you should 'commit' your changes**

## Branches
- many people working on a project
- issues arise when everybody has their hands on a single file
- changes more than a few lines of code should be done in branches
- as simple as `git switch -c <branch-name>`
- make your changes

## Merges
- when your ready, merge your changes into the main branch with `git switch main && git merge <branch-name>`
- all changes to the branch will be reflected in main

## Fork/PR 
- not everybody can edit your repo
- anybody can copy it
- pull requests are the official way to ask a project maintainer to pull your changes into their project. usually they'll review your changes and either accept the pull, offer suggestions you should change before they pull, or deny it altogether. 

## Fork cont.
- to contribute to someone else's project there are a few steps:
	- 'fork' the repo: usually a 'fork' button at the top of a repo's page
	- run `git clone <forked-repo>` 
	- make your changes & `git commit && git push`
	- submit a 'pull request'

# Practical Examples

## Stashing
- we all make mistakes
- what if we've made changes somewhere we don't want to
- just `git stash`

## Stashing cont.
- this will tuck away your changes where you can retrieve them later and restore your active tree to it's previous state
- e.g. you made changes to the wrong branch
	- `git stash`
	- `git switch <correct-branch>`
	- `git stash pop`

## Collaboration

## Oh crap
- you deleted a file in your tree and your IDE doesn't have it anywhere in it's history
- just `git checkout <last-commit-with-file> <file>`
- the file has returned to it's last commit'ed state
- this is why it's important to commit after each meaningful change

## Upstream Changes
- your working on a fork of a project
- the upstream project has made changes
- you can't submit a PR unless your fork includes those changes
- the GitHub Web-UI provides a way to do this
- there's an easier way:
- `git remote add <upstream-url>.git`
- `git fetch upstream`
- `git rebase upstream`

## Tagged Commits
- you're working on a project that people regularly install and depend on
- you want to keep your repository current with your changes, but these changes may not be stable
- you could use a different branch, but this isn't very transparent to the users nor is it best practice
- enter tagged commits

## Tagged Commits cont.5
- any commit that you designate can be tagged. 
- this is useful for showing your users which commit to use e.g. "release version"
- tags can be made at commit time with `git commmit -m "<your-tag-here>"` or afterwards with `git tag -a "<your-tag>" <commit-hash>`
- now when your users setup your project, then can rest assured that the major version tagged commit "should" be stable