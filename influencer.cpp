 /* Given a matrix of following relationships between N LinkedIn users (with ids from 0 to N-1):
     * followingMatrix[i][j] == true iff user i is following user j
     * thus followingMatrix[i][j] doesn't imply followingMatrix[j][i].
     *
     * An influencer is a user who is:
     * - followed by everyone else and
     * - not following anyone herself/himself
     *
     * This method should return the influencer's id in a given matrix of following relationships,
     * or return -1 if there is no influencer in this group */
     
     

int findInfluencer(int n, booelan[][] FM) {
    if (n == 0) return -1;
    int candidate = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i!=j && FM[i][j]) break;   
        }
        if (j == n) {
            candidate = i;
            break;
        }
    }
    if (candidate == -1) return -1;
    
    for (int i = 0; i < n; i++) {   
        if (!FM[i][candidate])
            return -1;
    }
    return candidate;
} 