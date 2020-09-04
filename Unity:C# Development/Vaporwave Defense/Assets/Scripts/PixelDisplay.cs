using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class PixelDisplay : MonoBehaviour
{
    [SerializeField] int pixels = 100;
    TextMeshProUGUI pixelText;


    void Start()
    {
        pixelText = GetComponent<TextMeshProUGUI>();
        UpdateDisplay();
    }

    private void UpdateDisplay()
    {
        pixelText.text = pixels.ToString();
    }

    public void AddPixels(int amount)
    {
        pixels += amount;
        UpdateDisplay();
    }

    public void SpendPixels(int amount)
    {
        if (pixels >= amount)
        {
            pixels -= amount;
            UpdateDisplay();
        }

    }
}

