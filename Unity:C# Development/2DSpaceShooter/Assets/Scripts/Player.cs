using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    [Header("Player")]
    [SerializeField] float moveSpeed = 10f;
    [SerializeField] float padding = 1f;
    [SerializeField] public int health = 300;
    
    [Header("Projectile")]
    [SerializeField] GameObject laserPrefab;
    [SerializeField] float projectileSpeed = 10f;
    [SerializeField] float projectileFiringPeriod = 0.1f;

    [Header("Sound Effects")]
    [SerializeField] AudioClip playerDeathSFX;
    [SerializeField] [Range(0, 1)] float playerDeathSFXVolume = 0.5f;
    [SerializeField] AudioClip playerLaserSFX;
    [SerializeField] [Range(0, 1)] float playerLaserSFXVolume = 0.5f;

    Coroutine firingCoroutine;

    float xMin;
    float xMax;

    float yMin;
    float yMax;

    // Start is called before the first frame update
    void Start()
    { 
        SetUpNewBoundaries();
        
    }

    
    // Update is called once per frame
    void Update()
    {
        Move();
        Fire();
    }

    private void Fire()
    {
        if (Input.GetButtonDown("Fire1"))
        {
            firingCoroutine = StartCoroutine(FireContinuously());
        }
        if (Input.GetButtonUp("Fire1"))
        {
            StopCoroutine(firingCoroutine);
        }
    }

    private void Move()
    {
        var deltaX = Input.GetAxis("Horizontal") * Time.deltaTime * moveSpeed;
        var deltaY = Input.GetAxis("Vertical") * Time.deltaTime * moveSpeed;

        var newXPos = Mathf.Clamp(transform.position.x + deltaX, xMin, xMax);
        var newYPos = Mathf.Clamp(transform.position.y + deltaY, yMin, yMax);

        transform.position = new Vector2(newXPos, newYPos);

    }

    private void SetUpNewBoundaries()
    {
        Camera gameCamera = Camera.main;
        xMin = gameCamera.ViewportToWorldPoint(new Vector3(0, 0, 0)).x + padding;
        xMax = gameCamera.ViewportToWorldPoint(new Vector3(1, 0, 0)).x - padding;

        yMin = gameCamera.ViewportToWorldPoint(new Vector3(0, 0, 0)).y + padding;
        yMax = gameCamera.ViewportToWorldPoint(new Vector3(0, 1, 0)).y - padding;
    }

    IEnumerator FireContinuously()
    {
        while (true)
        {
            GameObject laser = Instantiate(laserPrefab,
                                   transform.position,
                                   Quaternion.identity) as GameObject;
            laser.GetComponent<Rigidbody2D>().velocity = new Vector2(0f, projectileSpeed);
            AudioSource.PlayClipAtPoint(playerLaserSFX, Camera.main.transform.position, playerLaserSFXVolume);
            yield return new WaitForSeconds(projectileFiringPeriod);

        }
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        DamageDealer damageDealer = other.gameObject.GetComponent<DamageDealer>();
        if (!damageDealer) { return; }
        ProcessHit(damageDealer);
    }

    private void ProcessHit(DamageDealer damageDealer)
    {
        health -= damageDealer.GetDamage();
        damageDealer.Hit();
        if (health <= 0)
        {
            Die();
        }

    }

    public int GetHealth()
    {
        return health;
    }

    private void Die()
    {
        FindObjectOfType<Level>().LoadGameOver();
        Destroy(gameObject);
        AudioSource.PlayClipAtPoint(playerDeathSFX, Camera.main.transform.position, playerDeathSFXVolume);
        
    }
}
