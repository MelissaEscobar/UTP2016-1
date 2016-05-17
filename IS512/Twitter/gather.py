from tweepy import Stream
from tweepy import OAuthHandler
from tweepy.streaming import StreamListener
import json
import time

ckey ="ZhFyd0Y5Io75L2IeEVOaMQD9y"
csecret ="7J9Vz5ztSEU5CvaU1hvBgaBkIoEfj9C307AI2zXZmtOBseP99n"
atoken ="1881073382-PghwwBdUrqqx030LjDCONjBhP0ewTC0urpC9bhZ"
asecret ="eXFsaqYswh73E7IQNULNyuaoTfzcmZLUN2Ze40J6AkCR3"
pereira= [-75.790558,4.78139,-75.614777,4.867263] #Check it out, is a very nice city!
file =  open('tweets.txt', 'a')

class listener(StreamListener):

    def on_data(self, data):
        # Twitter returns data in JSON format - we need to decode it first
        try:
            decoded = json.loads(data)
        except Exception as e:
            print e #we don't want the listener to stop
            return True
   
        if decoded.get('geo') is not None:
            location = decoded.get('geo').get('coordinates')
        else:
            location = '[,]'
        text = decoded['text'].replace('\n',' ')
        user = '@' + decoded.get('user').get('screen_name')
        created = decoded.get('created_at')
        tweet = '%s|%s|%s|s\n' % (user,location,created,text)
        
        file.write(tweet)
        print tweet
        return True
if __name__ == '__main__':
    print 'Starting'
    auth = OAuthHandler(ckey, csecret)
    auth.set_access_token(atoken, asecret)
    twitterStream = Stream(auth, listener())
    twitterStream.filter(track="Colombia")
