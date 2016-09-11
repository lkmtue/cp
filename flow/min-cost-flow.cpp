struct MincostFlow {
	typedef long long T;
	static const T oo = (T) 1e18;
	static const int MAXV = 1000 + 10;
	static const int MAXE = 1000000 + 10;
	int n, s, t, E, adj[MAXE], next[MAXE], last[MAXV], which[MAXV];
	T totalCost, totalFlow, cap[MAXE], flow[MAXE], cost[MAXE], pot[MAXE], dist[MAXV];
	void init(int _n, int _s, int _t) {
		n = _n; s = _s; t = _t;
		memset(last, -1, sizeof(last)); E = 0;
	}
	void add(int u, int v, T ca, T co) {
		adj[E] = v; cap[E] = ca; flow[E] = 0; cost[E] = +co; next[E] = last[u]; last[u] = E++;
		adj[E] = u; cap[E] =  0; flow[E] = 0; cost[E] = -co; next[E] = last[v]; last[v] = E++;
	}
	void bellman() {
		int stop = 0;
		fill_n(pot, n, 0);
		while (!stop) {
			stop = 1;
			for (int u = 0; u < n; u++) for (int e = last[u]; e != -1; e = next[e]) if (flow[e] < cap[e]) {
				int v = adj[e];
				if (pot[v] > pot[u] + cost[e]) {
					pot[v] = pot[u] + cost[e];
					stop = 0;
				}
			}
		}
	}
	int dijkstra() {
		typedef pair<T, int> node;
		priority_queue<node, vector<node>, greater<node> > que;
		for (int u = 0; u < n; u++) dist[u] = oo;
		dist[s] = 0;
		que.push(make_pair(0, s));
		while (!que.empty()) {
			T dnow = que.top().first;
			int u = que.top().second;
			que.pop();
			if (dnow > dist[u]) continue;
			for (int e = last[u]; e != -1; e = next[e]) if (flow[e] < cap[e]) {
				int v = adj[e];
				T dnext = dnow + cost[e] + pot[u] - pot[v];
				if (dist[v] > dnext) {
					dist[v] = dnext;
					which[v] = e;
					que.push(make_pair(dnext, v));
				}
			}
		}
		return dist[t] < oo;
	}
	int maxflow(T desireFlow = oo) {
		totalCost = totalFlow = 0;
		bellman();
		while (totalFlow < desireFlow) {
			if (!dijkstra()) return 0;
			T delta = desireFlow - totalFlow;
			for (int v = t, e = which[v]; v != s; v = adj[e ^ 1], e = which[v]) delta = min(delta, cap[e] - flow[e]);
			for (int v = t, e = which[v]; v != s; v = adj[e ^ 1], e = which[v]) {
				flow[e] += delta;
				flow[e ^ 1] -= delta;
			}
			totalFlow += delta;
			totalCost += delta * (dist[t] - pot[s] + pot[t]);
			for (int u = 0; u < n; u++) pot[u] += dist[u];
		}
		return 1;
	}
} mcf;
