using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AttackerSpawner : MonoBehaviour
{
    bool spawn = true;
    [SerializeField] float maxSpawnDelay = 5f;
    [SerializeField] float minSpawnDelay = 1f;
    [SerializeField] Attacker attackerPrefab;


    // Start is called before the first frame update
    IEnumerator Start()
    {
        while (spawn)
        {
            yield return new WaitForSeconds(Random.Range(minSpawnDelay, maxSpawnDelay));
            SpawnerAttacker();
        }
    }

    // Update is called once per frame
    void Update()
    {
       
    }

    private void SpawnerAttacker()
    {
        Instantiate(attackerPrefab, transform.position, Quaternion.identity);
    }
}
