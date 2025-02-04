// https://leetcode.com/problems/get-watched-videos-by-your-friends/description/
import java.util.*;

class Solution {

    private void addVideoToHash(List<String> videos, Map<String, Integer> hash) {
        for(String video: videos) {
            if(!hash.containsKey(video)) {
                hash.put(video, 1);
            }
            hash.put(video, 1 + hash.get(video));
        }
    }

    public List<String> watchedVideosByFriends(List<List<String>> watchedVideos, int[][] friends, int id, int level) {
        int n = friends.length;
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);
        Map<String, Integer> hash = new HashMap<>();
        Queue<Integer> q = new LinkedList<>();
        q.add(id);
        visited[id] = true;
        int levelCount = 0;

        while(!q.isEmpty()) {
            int len = q.size();
            if(levelCount > level) {
                break;
            }
            for(int i = 0; i < len; i++) {
                int userId = q.poll();
                if(levelCount == level) {
                    this.addVideoToHash(watchedVideos.get(userId), hash);
                }
                for(int friendId: friends[userId]) {
                    if(!visited[friendId]) {
                        q.add(friendId);
                        visited[friendId] = true;
                    }
                }
            }
            levelCount++;
        }

        PriorityQueue<Object[]> pq = new PriorityQueue<>((a, b) -> {
            int countCompare = Integer.compare((int)a[0], (int)b[0]);
            if(countCompare != 0) {
                return countCompare;
            }
            return ((String)a[1]).compareTo((String)b[1]);
        });

        for(String key: hash.keySet()) {
            pq.add(new Object[] {hash.get(key), key});
        }

        List<String> answer = new ArrayList<>();
        while(!pq.isEmpty()) {
            answer.add((String)pq.poll()[1]);
        }
        return answer;
    }
}