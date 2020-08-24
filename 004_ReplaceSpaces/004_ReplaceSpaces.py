# -*- coding:utf-8 -*-

# class Solution:
#     def replaceSpace(self, s):
#         s_new = []
#         for i in s:
#             if i != ' ':
#                 s_new.append(i)
#             else:
#                 s_new.append('%20')
#         return ''.join(s_new)
#
# # -*- coding:utf-8 -*-
# class Solution:
#     def replaceSpace(self, s):
#         s_new=s.split(' ')
#         return '%20'.join(s_new)
#
# class Solution:
#     def replaceSpace(self, s):
#         return s.replace(' ', '%20')

class Solution:
    def replaceSpace(self, s):
        s_len=len(s)
        spaceCnt=0

        for i in s:
            if i==' ':
                spaceCnt+=1

        s_newLen=(spaceCnt<<1)+s_len
        s_new=[' ']*s_newLen
        j=0
        for i in range(s_len):
            if s[i]==' ':
                s_new[j]='%'
                s_new[j+1] = '2'
                s_new[j+2] = '0'
                j+=3
            else:
                s_new[j]=s[i]
                j+=1
        return ''.join(s_new)
