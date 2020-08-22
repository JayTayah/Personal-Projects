using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Level : MonoBehaviour
{

    [SerializeField] float delayInSeconds = 2f;

    public void LoadGameOver()
    {
        StartCoroutine(DelayGameOver()); 
    }

    public void LoadGame()
    {
        SceneManager.LoadScene("Game");
        FindObjectOfType<GameSession>().ResetGame();
    }

    public void LoadStartMenu()
    {
        SceneManager.LoadScene("Start Menu");
    }

    public void QuitGame()
    {
        Application.Quit();
    }

    IEnumerator DelayGameOver()
    {
        yield return new WaitForSeconds(delayInSeconds);
        SceneManager.LoadScene("Game Over");
    }


}
