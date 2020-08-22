using UnityEngine;

public class Ball : MonoBehaviour
{
    [SerializeField] Paddle paddle;
    [SerializeField] float initialVelocityX = 2f;
    [SerializeField] float initialVelocityY = 15f;
    [SerializeField] AudioClip[] ballSounds;
    [SerializeField] float randomFactor = 0.2f;



    Vector2 paddleToBallVector;
    bool hasStarted = false;

    AudioSource myAudioSource;
    Rigidbody2D myRigidBody;



    // Start is called before the first frame update
    void Start()
    {
        paddleToBallVector = transform.position - paddle.transform.position;
        myAudioSource = GetComponent<AudioSource>();
        myRigidBody = GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        if (!hasStarted)
        {
            LockBallToPaddle();
            LaunchOnMouseClick();
        }
    }

    private void LaunchOnMouseClick()
    {
        if (Input.GetMouseButtonDown(0))
        {
            hasStarted = true;
            myRigidBody.velocity = new Vector2(initialVelocityX, initialVelocityY);
        }
    }

    private void LockBallToPaddle()
    {
        Vector2 paddlePos = new Vector2(paddle.transform.position.x, paddle.transform.position.y);
        transform.position = paddleToBallVector + paddlePos;
    }


    private void OnCollisionEnter2D(Collision2D collision)
    {
        Vector2 veloctiyTweek = new Vector2
                                (Random.Range(0f, randomFactor),
                                Random.Range(0f,randomFactor));
        if (hasStarted)
        {
            AudioClip sound = ballSounds[Random.Range(0, ballSounds.Length)];
            myAudioSource.PlayOneShot(sound);
            myRigidBody.velocity += veloctiyTweek;
        }
    }
}
