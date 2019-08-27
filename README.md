# getCorrectDnsResult
a tool that can help you get correct dns result without use proxy (in China).

## usage: 

run the below command:

    stdbuf -i0 -o0 -e0 unbuffer  nohup  tshark -f "udp port 53" -Y "dns.qry.type == 1 and dns.flags.response == 1 and ip.src == 8.8.8.8" > nohup.out &

then compile c source file: 

    gcc -o act act.c

    gcc -o run run.c

then run the below command:

    ./run

you wil get a prompt:
    
    Please enter want to query domain:

input domain that you want to query, for example: 

    google.com 
    twitter.com
    facebook.com
