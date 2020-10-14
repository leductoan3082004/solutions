struct Trie_String{
    vector <vector<int> > T;
    vector <bool> End;
    int numNode;
    int cap, Base;
    Trie_String(){};
    Trie_String(int maxN, int _Base) {
        cap = maxN;
        Base = _Base;
        numNode = 0;
        T = vector<vector<int> > (cap, vector<int>(Base, 0));
        End = vector<bool> (cap, false); ///End[u] = true if we has a complete string in Node u
    }

    void add(string s) {
        int root = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a'; ///change if s not contain only alphabet
            assert(c >= 0 && c < Base);
            if (T[root][c] == 0) T[root][c] = ++numNode;
            root = T[root][c];
            assert(root < cap);
        }
        End[root] = true;
    }
    /// abcde
    /// abcfe
    bool find(string s) { ///if we have a complete string t = s then return true, else return false
        int root = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a'; ///change if s not contain only alphabet
            assert(c >= 0 && c < Base);
            if (T[root][c] == 0) return false;
            root = T[root][c];
        }
        return End[root];
    }

    bool findPrefix(string s) { ///if we have a complete string t so s is the prefix in t then return true, else return false
        int root = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - '0';
            if (T[root][c] == 0) return false;
            root = T[root][c];
        }
        return true;
    }

    ///add method
};
