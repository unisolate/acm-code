//===========================Shortest_Path=============

const int SPmaxn = 50000;

struct Shortest_Path
{
	struct member
	{
		int n, v;
		member(int a, int b) : n(a), v(b){}
	};
	
	int dist[SPmaxn], b[SPmaxn];
	priority_queue<member> q;
	
	int query(Link_Table_V &l, int s, int t)
	{
		memset(dist, 0x3f, sizeof(dist));
		memset(b, 0, sizeof(b));
		dist[s] = 0;
		while (!q.empty()) q.pop();
		q.push(member(s, 0));
		for (;;)
		{
			int k = -1;
			while (!q.empty())
			{
				k = q.top().n;
				if (!b[k]) break;
				k = -1;
				q.pop();
			}
			if (k == -1) break;
			if (k == t) return dist[t];
			b[k] = 1;
			for (int i = l.be(k); i; i = l.next(i))
			{
				int to = l.to(i), v = l.v(i);
				if (b[to]) continue;
				if (dist[k] + v >= dist[to]) continue;
				dist[to] = dist[k] + v;
				q.push(member(to, dist[to]));
			}
		}
		return -1;
	}
};

bool operator<(Shortest_Path::member a, Shortest_Path::member b) { return a.v > b.v; }

//===========================Shortest_Path=============