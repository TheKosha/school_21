#!/bin/zsh
rm -rf ~/Library/Caches/*
rm -rf ~/Library/42_cache
rm -rf ~/Library/Safari/*
rm -rf ~/.kube/cache/*
rm -rf ~/Library/Application\ Support/Slack/Service\ Worker/CacheStorage/
rm -rf ~/Library/Application\ Support/Slack/Cache/
rm -rf ~/Library/Application\ Support/Slack/Code\ Cache\
rm -rf ~/Library/Application\ Support/Code/Cache/*
rm -rf ~/Library/Application\ Support/Code/CachedData/*
rm -rf ~/Library/Application\ Support/Code/User/workspaceStoratge
rm -rf ~/Library/Containers/com.docker.docker/Data/vms/*

#!/bin/bash
rm -rfv ~/Library/Caches/*
rm -rfv ~/Library/Application\ Support/Slack/Cache/*
rm -rfv ~/Library/Application\ Support/Slack/Service\ Worker/CacheStorage/*
rm -rfv ~/Library/Group\ Containers/6N38VWS5BX.ru.keepcoder.Telegram/account-570841890615083515/postbox/*
rm -rfv ~/Library/Caches
rm -rfv ~/Library/Application\ Support/Code/Cache
rm -rfv ~/Library/Application\ Support/Code/CachedData
rm -rfv ~/Library/Application\ Support/Code/CachedExtension
rm -rfv ~/Library/Application\ Support/Code/CachedExtensions
rm -rfv ~/Library/Application\ Support/Code/CachedExtensionVSIXs
rm -rfv ~/Library/Application\ Support/Code/Code\ Cache
rm -rfv ~/Library/Application\ Support/Slack/Cache
rm -rfv ~/Library/Application\ Support/Slack/Code\ Cache
rm -rfv ~/Library/Application\ Support/Slack/Service\ Worker/CacheStorage
rm -rfv ~/Library/Application\ Support/Code/User/workspaceStorage
echo -en "\033[31mSpace for the space!\n\033[0m"
free_space=$(df -h | grep 'lallison' | awk '{print $4}')
echo -en "\033[32m${free_space} are available now\n\033[0m"
df -h ~