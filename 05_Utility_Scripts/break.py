import numpy as np
from scipy.spatial import ConvexHull
from itertools import combinations

def parse_points(filename):
    points = []
    with open(filename, 'r') as file:
        for line in file:
            # Strip parentheses and split by commas
            line = line.strip()[1:-1]
            x, y, z, n = map(float, line.split(','))
            points.append((x, y, z, int(n)))
    return points

def volume_of_tetrahedron(p1, p2, p3, p4):
    AB = np.array([p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]])
    AC = np.array([p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]])
    AD = np.array([p4[0] - p1[0], p4[1] - p1[1], p4[2] - p1[2]])

    volume = abs(np.dot(AD, np.cross(AB, AC))) / 6.0
    return volume

def find_min_volume_tetrahedron(points):
    points_np = np.array([(x, y, z) for x, y, z, n in points])
    hull = ConvexHull(points_np)
    hull_points = [points[idx] for idx in hull.vertices]

    min_volume = float('inf')
    min_tetrahedron = None

    for combo in combinations(hull_points, 4):
        if sum(p[3] for p in combo) == 100:
            volume = volume_of_tetrahedron(combo[0], combo[1], combo[2], combo[3])
            if volume < min_volume:
                min_volume = volume
                min_tetrahedron = combo

    if min_tetrahedron:
        indices = sorted(points.index(p) for p in min_tetrahedron)
        return indices, min_volume
    else:
        return None, None

def find_min_volume_tetrahedron_brute_force(points):
    min_volume = float('inf')
    min_tetrahedron = None

    for combo in combinations(points, 4):
        if sum(p[3] for p in combo) == 100:
            volume = volume_of_tetrahedron(combo[0], combo[1], combo[2], combo[3])
            if volume < min_volume:
                min_volume = volume
                min_tetrahedron = combo

    if min_tetrahedron:
        indices = sorted(points.index(p) for p in min_tetrahedron)
        return indices, min_volume
    else:
        return None, None

def main():
    points_small = parse_points('points_small.txt')
    points_large = parse_points('points_large.txt')

    small_indices_opt, small_volume_opt = find_min_volume_tetrahedron(points_small)
    small_indices_brute, small_volume_brute = find_min_volume_tetrahedron_brute_force(points_small)

    if small_indices_opt:
        print("Small file optimized tetrahedron indices:", small_indices_opt)
        print("Small file optimized tetrahedron volume:", small_volume_opt)
    
    if small_indices_brute:
        print("Small file brute force tetrahedron indices:", small_indices_brute)
        print("Small file brute force tetrahedron volume:", small_volume_brute)
    
    if small_indices_opt and small_indices_brute:
        if small_indices_opt == small_indices_brute:
            print("Optimized and Brute Force methods found the same tetrahedron for the small file.")
        else:
            print("Optimized and Brute Force methods found different tetrahedrons for the small file.")
    
    large_indices_opt, large_volume_opt = find_min_volume_tetrahedron(points_large)
    large_indices_brute, large_volume_brute = find_min_volume_tetrahedron_brute_force(points_large)

    if large_indices_opt:
        print("Large file optimized tetrahedron indices:", large_indices_opt)
        print("Large file optimized tetrahedron volume:", large_volume_opt)
    
    if large_indices_brute:
        print("Large file brute force tetrahedron indices:", large_indices_brute)
        print("Large file brute force tetrahedron volume:", large_volume_brute)
    
    if large_indices_opt and large_indices_brute:
        if large_indices_opt == large_indices_brute:
            print("Optimized and Brute Force methods found the same tetrahedron for the large file.")
        else:
            print("Optimized and Brute Force methods found different tetrahedrons for the large file.")

if __name__ == "__main__":
    main()


tried to optimize the question using conver hull in 3D trying to find the min tetrahedron maintaining the fact that sum of n is 100, couldn't fully write the correct solution, watched a lot of videos to understand the concept though, overall it was a nice question small.txt was solved using the naive approach and i already took 3 days to come up with the optimized solution didn't want to invest more time given the time frame of the submission, if you do read this please reach out to me not for an interview but I would like to just talk about your company and your mission you are trying to achieve using breadcrumb.ai, my final answer i have submitted for large is what i found the min volume to be using my naive code that I have attached with the submission.