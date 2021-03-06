<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * accordancesystems theme.
 */

/**
 * Implements theme_breadcrumb().
 */
function accordancesystems_breadcrumb(&$variables) {
  $output = '';
  if (!empty($variables['breadcrumb'])) {
    $output = '<div id="breadcrumb" class="breadcrumb-container clearfix"><h2 class="element-invisible">You are here</h2><ul class="breadcrumb">';
    $switch = array('odd' => 'even', 'even' => 'odd');
    $zebra = 'even';
    $last = count($variables['breadcrumb']) - 1;
    $seperator = '<span class="breadcrumb-seperator">/</span>';
    foreach ($variables['breadcrumb'] as $key => $item) {
      $zebra = $switch[$zebra];
      $attributes['class'] = array('depth-' . ($key + 1), $zebra);
      if ($key == 0) {
        $attributes['class'][] = 'first';
      }
      if ($key == $last) {
        $attributes['class'][] = 'last';
        $output .= '<li' . drupal_attributes($attributes) . '>' . $item . '</li>' . '';
      }
      else
        $output .= '<li' . drupal_attributes($attributes) . '>' . $item . '</li>' . $seperator;
      }
    $output .= '</ul></div>';
    return $output;
  }
}

/**
 * Implements hook_html_head_alter().
 */
function accordancesystems_html_head_alter(&$head_elements) {
  // Add initial-scale to viewport meta tag.
  if (isset($head_elements['omega-viewport'])) {
    $head_elements['omega-viewport']['#attributes']['content'] .= ', initial-scale=1.0';
  }
}
