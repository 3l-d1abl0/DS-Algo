import requests
import base64
from tqdm import tqdm


#master_json_url = 'https://178skyfiregce-a.akamaihd.net/exp=1474107106~acl=%2F142089577%2F%2A~hmac=0d9becc441fc5385462d53bf59cf019c0184690862f49b414e9a2f1c5bafbe0d/142089577/video/426274424,426274425,426274423,426274422/master.json?base64_init=1'
master_json_url = 'https://176skyfiregce-vimeo.akamaized.net/exp=1527630147~acl=%2F242216175%2F%2A~hmac=39f86df53245446ab54b2a692a3976eb4cebcd78b9087cebb52cbf13f97c2d1b/242216175/sep/video/882174671,882174733,882174676,882174657/master.json?base64_init=1'
base_url = master_json_url[:master_json_url.rfind('/', 0, -26) + 1]

resp = requests.get(master_json_url)
content = resp.json()

heights = [(i, d['height']) for (i, d) in enumerate(content['video'])]
idx, _ = max(heights, key=lambda (_, h): h)
video = content['video'][idx]
video_base_url = base_url + video['base_url']
print 'base url:', video_base_url

#filename = 'video_%d.mp4' % video['id']
filename = 'video_MOM.mp4'# % video['id']
print 'saving to %s' % filename

video_file = open(filename, 'wb')

init_segment = base64.b64decode(video['init_segment'])
video_file.write(init_segment)

for segment in tqdm(video['segments']):
    segment_url = video_base_url + segment['url']
    resp = requests.get(segment_url, stream=True)
    if resp.status_code != 200:
        print 'not 200!'
        print resp
        print segment_url
        break
    for chunk in resp:
        video_file.write(chunk)

video_file.flush()
video_file.close()

'''
ffmpeg command is: ['ffmpeg.exe', '-i', 'D:\\codebase\\py\\vimeo-download\\temp\\20180529-224643-271\\a.mp3', '-i', 'D:\\codebase\\py\\vimeo-download\\temp\\20180529-224643-271\\v.mp4', '-acodec', 'copy', '-vcodec', 'copy', 'D:\\codebase\\py\\vimeo-download\\output\\mom.mp4.mp4']

ffmpeg.exe -i D:\\codebase\\py\\vimeo-download\\temp\\20180529-224643-271\\a.mp3 -i D:\\codebase\\py\\vimeo-download\\temp\\20180529-224643-271\\v.mp4 -acodec copy -vcodec copy D:\\codebase\\py\\vimeo-download\\output\\mom.mp4.mp4




        Please mention :
        Current CTC:
        Expected CTC :
        Notice Period :
        How soon you can join :
        Exp in Python Development :
        Exp in SQL & NoSQL :
        Rating on DS on 10 : 
        Rating on Algo on 10 : 
        Available for interviews on weekdays :




'''


Kate was given a birthday gift of three theater tickets. Now she is browsing the theater program for the next N days. On the program, performances are named by integers. Every day, one performance is staged. Kate wants to choose three days (not necessarily consecutive) to go to the theater.

In how many ways can she use her tickets? Two ways are different if the sequences of watched performances are different. Kate likes the theater, so she may watch one performance more than once. For example, if N = 4 and theater program looks as following: [1, 2, 1, 1], Kate has four possibilities to choose the dates: [1, 2, 1, 1], [1, 2, 1, 1], [1, 2, 1, 1], and [1, 2, 1, 1], but they create only three different sequences: (1, 2, 1), (1, 1, 1) and (2, 1, 1). The correct answer for this example is 3. Notice that the order of performances matters, so the first and the last sequences are considered different.

Write a function:

class Solution { public int solution(int[] A); }

that, given an array A consisting of N integers, denoting names of performances for the next N days, returns the number of possible ways to spend the tickets. Since the answer can be very large, provide it modulo 109 + 7 (1,000,000,007).

For example, given A = [1, 2, 1, 1], the function should return 3 as exmplained above.

Given A = [1, 2, 3, 4], the function should return 4. There are four ways to spend tickets: (1, 2, 3), (1, 2, 4), (1, 3, 4) and (2, 3, 4).

Given A = [2, 2, 2, 2], the function should return 1. There is only one way to spend tickets: (2, 2, 2).

Given A = [2, 2, 1, 2, 2], the function should return 4. There are four ways to spend tickets: (1, 2, 2), (2, 1, 2), (2, 2, 1) and (2, 2, 2).

Given A = [1, 2], the function should return 0. Kate cannot use all three tickets in only two days.

Assume that:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [1..N].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N) (not counting the storage required for input arguments).
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.


C++, JavaScript (Intermediate), PHP (Intermediate), Python (Basic), Java(Basic), MySQL, MongoDB (Basics), Linux,Zend Framework, Node.JS, Svn, Git, AWS, JQuery, Bootstrap3, Data Structures and Algorithms


9019259568


Co-ordinated with Sales and Marketing Team for rapid changes in layout, content across the
different sections of the Website as well as built several admin tools to ease their work.
Assisted Deployment in production environments, investigated and resolved critical
production issues independently as a part of Service On-call.


